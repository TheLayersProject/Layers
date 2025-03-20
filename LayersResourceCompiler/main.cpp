/*
 * Copyright (C) 2025 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <filesystem>
#include <Layers/lalgorithms.h>
#include <Layers/ljson.h>

namespace fs = std::filesystem;

// Helper function: convert a string into a valid C++ identifier by replacing non-alphanumeric characters with underscores.
std::string sanitize_identifier(const std::string& s)
{
    std::string result;
    for (char c : s)
    {
        result += std::isalnum(static_cast<unsigned char>(c)) ? c : '_';
    }
    return result;
}

// Helper function: generate a C++ array definition from binary data.
std::string generate_cpp_array(const std::vector<unsigned char>& data, const std::string& var_name)
{
    std::ostringstream oss;
    oss << "static const unsigned char " << var_name << "[] = {";
    for (size_t i = 0; i < data.size(); ++i) {
        if (i % 16 == 0)
            oss << "\n    ";
        oss << "0x" << std::hex << std::setw(2) << std::setfill('0')
            << static_cast<int>(data[i]);
        if (i != data.size() - 1)
            oss << ", ";
    }
    oss << "\n};\n";
    oss << "static const size_t " << var_name << "_size = sizeof(" << var_name << ");\n";
    return oss.str();
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: resource_compiler <resource_json_file> <output_cpp_file>\n";
        return 1;
    }

    std::string resourceJsonFile = argv[1];
    std::string outputCppFile = argv[2];

    // Determine the directory where the JSON file resides.
    fs::path jsonPath = fs::absolute(fs::path(resourceJsonFile));
    fs::path baseDir = jsonPath.parent_path();

    // Read the JSON file into a string.
    std::ifstream jsonFile(resourceJsonFile);
    if (!jsonFile)
    {
        std::cerr << "Error: Unable to open " << resourceJsonFile << "\n";
        return 1;
    }
    std::stringstream buffer;
    buffer << jsonFile.rdbuf();
    std::string jsonContent = buffer.str();

    jsonContent = Layers::remove_whitespace(jsonContent);

    // Parse the JSON using your Layers JSON code.
    // Create a lexer and parser and expect the root to be an object.
    Layers::LJsonLexer lexer(jsonContent);
    Layers::LJsonParser parser(lexer);
    Layers::LJsonObject root;
    try
    {
        root = parser.parse_object();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error parsing JSON: " << e.what() << "\n";
        return 1;
    }

    std::ostringstream arraysStream;
    // Vector of pairs: (virtual resource path, generated identifier)
    std::vector<std::pair<std::string, std::string>> resourceEntries;

    // Iterate over the JSON object.
    // The expected JSON structure is:
    // {
    //     "/definitions/qlayers": [ "qlbox.json", "qlcheckbox.json", ... ]
    // }
    for (const auto& pair : root)
    {
        // pair.first is an LString and pair.second is an LJsonValue.
        // Convert the LString key to std::string (assuming LString provides c_str()).
        std::string virtualPrefix(pair.first.c_str());

        // Ensure the value is an array.
        if (!pair.second.is_array())
        {
            std::cerr << "Warning: Value for key " << virtualPrefix << " is not an array, skipping.\n";
            continue;
        }
        Layers::LJsonArray fileList = pair.second.to_array();
        for (const Layers::LJsonValue& fileVal : fileList) 
        {
            if (!fileVal.is_string()) {
                std::cerr << "Warning: File name in array for key " << virtualPrefix << " is not a string, skipping.\n";
                continue;
            }
            // Convert the LJsonValue's string to std::string.
            std::string fileName(std::string(fileVal.to_string().c_str()));

            // Construct the virtual path.
            std::string virtualPath;
            if (!virtualPrefix.empty() && virtualPrefix.back() != '/')
                virtualPath = virtualPrefix + "/" + fileName;
            else
                virtualPath = virtualPrefix + fileName;

            // Construct the local file path (assuming the file is in the same directory as the JSON file).
            fs::path localFilePath = baseDir / fileName;
            if (!fs::exists(localFilePath))
            {
                std::cerr << "Warning: File " << localFilePath << " not found, skipping.\n";
                continue;
            }

            // Open and read the file in binary mode.
            std::ifstream infile(localFilePath, std::ios::binary);
            if (!infile)
            {
                std::cerr << "Warning: Cannot open file " << localFilePath << ", skipping.\n";
                continue;
            }
            std::vector<unsigned char> data((std::istreambuf_iterator<char>(infile)),
                std::istreambuf_iterator<char>());
            infile.close();

            // Create a unique identifier based on the virtual path.
            std::string identifier = "res_" + sanitize_identifier(virtualPath);

            // Generate the C++ array code.
            arraysStream << generate_cpp_array(data, identifier) << "\n";

            // Store the resource entry.
            resourceEntries.push_back({ virtualPath, identifier });
        }
    }

    // Generate the ResourceEntry structure and the registry array.
    std::ostringstream entriesStream;
    entriesStream << "struct ResourceEntry {\n"
        << "    const char* path;\n"
        << "    const unsigned char* data;\n"
        << "    size_t size;\n"
        << "};\n\n";
    entriesStream << "static const ResourceEntry resourceEntries[] = {\n";
    for (const auto& entry : resourceEntries)
    {
        entriesStream << "    { \"" << entry.first << "\", " << entry.second << ", " << entry.second << "_size },\n";
    }
    entriesStream << "};\n";

	// Generate the initResources function.
    std::ostringstream resourceInitializationStream;
    resourceInitializationStream << "void initResources_"
        << std::filesystem::path(outputCppFile).stem().string() << "()\n"
        << "{\n"
        << "    lResourceManager.init(resourceEntries, sizeof(resourceEntries)/sizeof(resourceEntries[0]));\n"
        << "};\n";

    // Write out the generated C++ source file.
    std::ofstream outFile(outputCppFile);
    if (!outFile)
    {
        std::cerr << "Error: Cannot write to output file " << outputCppFile << "\n";
        return 1;
    }
    outFile << "// Auto-generated resource file\n"
        << "#include <cstddef>\n"
        << "#include <Layers/lresources.h>\n\n"
        << "namespace Layers {\n"
        << "namespace Resources {\n\n"
        << arraysStream.str() << "\n"
        << entriesStream.str() << "\n"
        << resourceInitializationStream.str() << "\n"
        << "} // namespace Resources\n"
        << "} // namespace Layers\n";
    outFile.close();

    std::cout << "Resource file generated: " << outputCppFile << "\n";
    return 0;
}
