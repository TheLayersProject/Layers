# Layers

![Layers Logo Image](https://github.com/TheLayersProject/Layers/blob/main/images/layers_logo.svg?raw=true)

### Caution:

**Layers is still under active development.  It is not yet recommended for production use. Developers should proceed with caution.**

Layers is a C++ library that provides a framework for application themes and user-customization. The goal of Layers is to *let users decide* by making every aspect of an application's appearance customizable.

Developers can integrate Layers with their apps to give this customizability to their users. Integration begins with the concept of a *definable widget*, which is a [widget](https://en.wikipedia.org/wiki/Graphical_widget) whose appearance can be represented with a Layers *definition*.

Layers introduces three data structures:

- **Definitions** - A definition defines the hierarchy and default attribute values of a definable widget.
- **Themes** - A theme is a special definition that contains a small set of attributes intended to be linked to by a majority of definition attributes, directly or indirectly. This means that most of an app's appearance is controlled by the theme.
- **Styles** - A style overrides a definition to allow for very specific changes. Users can personalize any aspect of an app using styles.

Developers need to create a set of definitions for the widgets of their Layers software. Users create themes and styles to personalize apps.

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
