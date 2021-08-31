# Changelog
All notable changes to this project will be documented in this file.

## Alpha Phase

### [Layers 2.1.0a] - Unreleased
- "Default" and "Common" states are gone. Attributes are now created as stateful or stateless. This makes customization of themeables that use both types of attributes much clearer.
- The corner radii attribute widget has been redesigned and takes up less space.
- Layers applications will no longer store theme files in a universal 'Layers'/'Layers-alpha' folder in the user's app data directory. Instead, each individual application will store its own set of theme files in a folder named after the application.
- Created a mechanism to update theme files
- Created a mechanism to collapse text buttons in the Customize menu's topbar

### [Layers 2.0.0a] - 2021-06-23
- Layers has been fully rewritten.
- Theme swapping and customization application are now instant (This is expected to remain the case, but there is no guarantee)
- Reworked the Customize menu. Expanded customization for all widgets and improved widget hierarchy navigation
- Rounded corner support. Many widgets now use rounded corners by default
- Most buttons and controls have increased padding around their content and increased spacing between each other to improve touch experience
- Widget attributes are now applied via paint events instead of invoking stylesheets
- Pop-up boxes are now separate windows
- Changed the alpha save directory to "C:/Users/{Your username}/AppData/Local/Layers-alpha"