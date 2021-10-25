# Changelog
All notable changes to this project will be documented in this file.

## Alpha Phase

### [Layers 2.3.0a] - Unreleased
- Collapsed text button widget is now a different color to prevent the text buttons from disappearing 
- Fixed outline color and corner color customizations
- Fixed App Preferences settings panel customizations
- Fixed child widget stateful attributes being placed under the stateless label
- Fixed some issues where the preview window had too much functionality enabled
- Combobox items are no longer editable by default
- Button text can word wrap now
- Widgets of the Customize menu's topbar are now customizable
- Reworked application initialization
- New classes: GitHubRepo, MenuBar, TabBar, Version
- Image sequences can now be saved and loaded as a single file
- Reworked the ScrollArea class to make it themeable
- Created Theme::consume(theme) function for applications to add their widget's theme values to the library's default themes
- The Attribute class now inherits QObject, enabling it to work with signals/slots
- Attribute value change detection is now possible via the Attribute::value_changed signal
- AttributeSets now support attribute proxies.  An attribute in the set can be replaced with a proxy attribute from another widget.
- Between attribute value change detection and attribute proxies, there is no longer a need to support attribute sharing functionality. The AttributeSharingCombo class has been deprecated and removed.
- Previously, when setting an attribute's value, it would just set the value without checking if the attribute already had that value. Now it performs that check, resulting in a performance boost and better protection.

### [Layers 2.2.0a] - 2021-09-11
- Migrated to Qt 6
- Created a mechanism to update the application during start up
- Application settings are now stored in the registry system.
- The active theme selected by the user will now be applied automatically when the application is launched again.
- Prebuilt themes are now stored within the program and not in the app's theme folder.
- Fixed an issue with the theme file updating functionality that caused themes from old versions to be missing attribute sets and attributes for widgets created in later versions

### [Layers 2.1.0a] - 2021-09-01
- "Default" and "Common" states are gone. Attributes are now created as stateful or stateless. This makes customization of themeables that use both types of attributes much clearer.
- The corner radii attribute widget has been redesigned and takes up less space.
- Layers applications will no longer store theme files in a universal 'Layers'/'Layers-alpha' folder in the user's app data directory. Instead, each individual application will store its own set of theme files in a folder named after the application.
- Created a mechanism to update theme files. Themes created in 2.0.0a will get updated and continue to work in this version.
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