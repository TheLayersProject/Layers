# Changelog
All notable changes to this project will be documented in this file.

## Alpha Phase

### 2.3.0a (Unreleased)
- The Attribute class now inherits QObject to provide signal/slot functionality.
- Created a Variant class that wraps a QVariant and inherits QObject to provide signal/slot functionality.
    ○ Attributes store Variants which are made to be replaceable. An Attribute can replace its Variant with another Attribute's Variant. If either Attribute makes a change to the Variant, both Attributes get updated.
    ○ When Variants update, it emits Variant::changed, and the Attributes linked to them emit the Attribute::value_changed signal. This mechanism is referred to as attribute value change detection, and it replaces the AttributeSharingCombo. The AttributeSharingCombo class has been deprecated and removed.
- Previously, when setting an attribute's value, the value would be set without checking if the attribute already had that value. Now it performs that check, resulting in a performance boost and better protection. (TODO: NEED TO CHECK THIS AGAIN!)
- The AttributeSet class has been removed.
    ○ Slightly different data structures are now used for storing attributes between Themes and Themeables.
    ○ Widget attributes are now initialized as public member variables, removing the need to iterate each time an Attribute needs to be referenced.
- Created Theme::consume(theme) function for applications to add their widget's theme values to the library's default themes (TODO: NEED TO CHECK THIS AGAIN!)
- Removed issue_update() since widgets can connect update() to Attribute::value_changed.
- Previously, all CustomizePanels were initialized and acquired when the application was launched. This resulted in a large amount of memory being used which was unnecessary because the user only interacts with a single CustomizePanel at a time. Now, CustomizePanels are generated during runtime as the user navigates the widget hierarchy.
- Renamed various AttributeWidget classes
- Created the AttributeGroup and AttributeLayout classes to simplify the creation of AttributeWidgets and specify their organization in CustomizePanels
- Created a FillControl class that simplifies setting color/gradient values and toggling between them.
- Created the StateAW (State Attribute Widget) class which provides an improved interface for customizing stateful attributes.
- The NumberAW (formerly known as NumberAttributeWidget) now utilizes a mini slider and takes up less space.
- More widgets are customizable:
    ○ Widgets of the Customize menu's topbar
    ○ Dialogs
    ○ ScrollAreas
    ○ Fixed App Preferences settings panel customizations
- More widget attributes are customizable:
    ○ Widget margins
    ○ Widgets can now be filled with gradients.
    ○ Fixed outline color and corner color customizations
- Collapsed text button widget is now a different color to prevent the text buttons from disappearing 
- Reworked application initialization
    ○ A GitHubRepo class has been created to clarify that the string argument representing a GitHub repo provided for app initialization is a GitHub repo.
    ○ A Version class has been created to clarify that the string argument representing the app version provided for app initialization is a Version.
- Created new widget classes, MenuBar and TabBar.
- Image sequences can now be saved and loaded as a single file
- Fixed some issues where the preview window had too much functionality enabled
- Combobox items are no longer editable by default
- Button text can word wrap now

### 2.2.0a (September 11, 2021)
- Migrated to Qt 6
- Created a mechanism to update the application during start up
- Application settings are now stored in the registry system.
- The active theme selected by the user will now be applied automatically when the application is launched again.
- Prebuilt themes are now stored within the program and not in the app's theme folder.
- Fixed an issue with the theme file updating functionality that caused themes from old versions to be missing attribute sets and attributes for widgets created in later versions

### 2.1.0a (September 1, 2021)
- "Default" and "Common" states are gone. Attributes are now created as stateful or stateless. This makes customization of themeables that use both types of attributes much clearer.
- The corner radii attribute widget has been redesigned and takes up less space.
- Layers applications will no longer store theme files in a universal 'Layers'/'Layers-alpha' folder in the user's app data directory. Instead, each individual application will store its own set of theme files in a folder named after the application.
- Created a mechanism to update theme files. Themes created in 2.0.0a will get updated and continue to work in this version.
- Created a mechanism to collapse text buttons in the Customize menu's topbar

### 2.0.0a (June 23, 2021)
- Layers has been fully rewritten.
- Theme swapping and customization application are now instant (This is expected to remain the case, but there is no guarantee)
- Reworked the Customize menu. Expanded customization for all widgets and improved widget hierarchy navigation
- Rounded corner support. Many widgets now use rounded corners by default
- Most buttons and controls have increased padding around their content and increased spacing between each other to improve touch experience
- Widget attributes are now applied via paint events instead of invoking stylesheets
- Pop-up boxes are now separate windows
- Changed the alpha save directory to "C:/Users/{Your username}/AppData/Local/Layers-alpha" 