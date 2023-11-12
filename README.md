# Layers

<img src="https://github.com/TheLayersProject/Layers/blob/main/images/layers_logo.svg?raw=true" alt="Layers Logo Image"/>

Layers is a C++ library that provides a framework for user-customizable application themes. Layers is built with the philosophy that users should have a say in how their applications look. It offers both developers and users more control over application aesthetics. 

## Theme Framework

Layers introduces a theme framework that combines flexibility with efficiency. It's a practical solution for developers looking to offer customizable themes in their applications, and for users eager to personalize their app experience. 

### Structured Theme Storage

-   **Theme Directory:** A theme is organized into a directory of files and sub-directories.
-   **JSON-Based:** Theme files are stored in JSON format.
-   **Implementation Sets:** An implementation set is a collection of theme files designed to implement the theme for specific applications. Sets are stored as sub-directories within the theme directory.

### Customization Across Multiple Apps

-   **Generalized Customization:** Includes a general implementation set that allows for broad customization across different applications. 
-   **App-Specific Customization:** Implementation sets can be defined for specific applications, allowing for highly targeted customization.

### Versatile Attributes

-   **What Are Attributes?:** Attributes are the value containers in Layers. Each basic attribute has a *name* and a *value*.
-   **Attribute Linking:** An attribute can be *linked to* another attribute. In this case, it will use the value of the other attribute instead of its own.
-   **Attribute Overriding:** An attribute can be *overridden* by sub-attributes based on state-specific conditions, such as a fill color changing when a user hovers over a button.

### Other Features

-   **Efficient Loading:** To save system resources, only the metadata for a theme is initially loaded. Implementation sets are loaded as needed.
-   **Lineage Tracking**: Themes maintain a record of their ancestor themes in their metadata. This feature may be useful in the future to aid in compatibility.

## Layers Development

### Documentation

**NOTE: Documentation is NOT 100% complete at this time!**

Documentation for Layers can be found at the following site:

[https://docs.layersproject.org/Layers](https://docs.layersproject.org/Layers)

### Building

Steps to build Layers are detailed in the Layers documentation:

[https://docs.layersproject.org/Layers/0.17/build.html](https://docs.layersproject.org/Layers/0.17/build.html)

## Authors

-   **Hunter Malm** ([huntermalm](https://github.com/huntermalm)) - _Creator/Lead Developer_

See also the list of [contributors](https://github.com/TheLayersProject/Layers/contributors) who have participated in this project.

## License

This project is licensed under the LGPLv3. See the [LICENSE](https://github.com/TheLayersProject/Layers/blob/main/LICENSE) file for details.
