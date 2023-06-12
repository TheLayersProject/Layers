# Layers

<img src="https://github.com/huntermalm/Layers/blob/main/LayersWidgets/images/layers_banner.svg?raw=true" alt="layers_banner"/>

Layers is a Qt library that provides an application template with a focus on themes and user customization.

With Layers, you will be able to create simple, modern desktop apps that give users the freedom to change the appearance of your apps!

Features include:

- Template window with built-in features
- Theme creation and customization
- Themes that work across multiple apps
- User-friendly control widgets
- Updating system for apps hosted on GitHub

**NOTE: At this time, Layers only supports Windows. Other operating systems will be supported in the future.**

## Development and Testing

### Building Layers

These are the steps to build Layers from source-code with Microsoft Visual Studio (MSVC).

1. Install [Microsoft Visual Studio 2022](https://visualstudio.microsoft.com/downloads/) (2019 should also work)
    - Be sure to select *Desktop development with C++* from *Workloads*
2. Install the *Qt Visual Studio Tools* extension
    - Launch VS
    - From the menu bar, select *Extensions > Manage Extensions*
    - Search for *Qt Visual Studio Tools* and download it
    - Exit VS for the extension to install
3. Install Qt 6.5.x for open source use
    - Download [Qt Online Installer](https://www.qt.io/download-qt-installer-oss) and run it
    - When you get to the section labeled *Installation Folder*, choose the *Custom Installation* option
    - When you get to the section labeled *Select Components*, select the following options:
        - *Qt > Qt 6.5.x > MSVC 2019 64-bit*
        - *Qt > Developer and Designer Tools > OpenSSL 1.1.1q Toolkit*
4. Link the downloaded Qt version with Visual Studio
    - Launch VS
    - From the menu bar, select *Extensions > Qt VS Tools > Qt Versions*
    - Under *Version*, click the option to *add new Qt version*
    - Label the version as *6.5*
    - Under *Path*, click the folder icon and browse to the qmake executable from the Qt installation. It should be in the following directory
        - <i>...\Qt\6.5.x\msvc2019_64\bin</i>
5. Build Layers
    - Clone this project
    - Open the solution file *Layers.sln*
    - From the menu bar, select *Build > Build Solution*

### Testing Layers

To test Layers, select *Debug > Start Debugging* from the menu bar. This will launch the *Layers Demo* application.

### Documentation

Documentation for Layers can be found at [here](https://huntermalm.github.io/Layers/).

**NOTE: Layers Documentation is NOT 100% complete at this time!**

## Authors

* Hunter Malm - *Project creator/Lead developer* - [huntermalm](https://github.com/huntermalm)

See also the list of [contributors](https://github.com/huntermalm/Layers/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/huntermalm/Layers/blob/main/LICENSE) file for details.
