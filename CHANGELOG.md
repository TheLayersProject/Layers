# Changelog
All notable changes to this project will be documented in this file.

## Alpha Phase

### 4.0.0a (Unreleased)
    - Implemented the Data class which either stores a single variant or multiple state-variant pairs
    - Implemented the AbstractAttribute class which now serves as the abstract parent class of Attribute and AttributeGroup.
    - Attribute groups are now recognized by themes
    - Attribute groups are now disableable
    - Now using the term 'entangle' to describe the action of forcing one attribute to discard its data and use the data of another attribute.
    - Capitalized attribute names are now derived
    - Attribute now emits value_changed() if the state is set. This fixed some cases where themeables connected to multi-valued attributes didn't update properly.
    - Member attributes are now private with public access functions.
    - Themes are now stored in the AppData/Local/Layers directory which has been reinstated to aid multiple app support for themes.
    - Implemented theme directories and app/theme UUIDs
    - Theme directories now contain a file labeled meta.json. It stores the metadata regarding the theme.
    - Implemented theme meta-loading. When a Layers app is initialized, instead of fully loading all the themes, only their metadata is loaded. Only the active theme is fully loaded.
    - The functionality that loaded theme data from JSON files has been moved from the Theme constructor into a separate member function, Theme::load_document(). It can be called multiple times to load multiple theme files into a single Theme instance.
    - Theme::consume() has been removed in favor of Theme::load_document()
    - Improved the loading method for default themes. They are loaded as theme directories now which allows the the app implementations to be loaded at the same time. Previously, default themes were loaded from individual files which meant that the app implementations would have to manually loaded afterwards.
    - Themes now keep track of their lineage.
    - Created a generic form of Themeable::apply_theme_attributes(), and merged it into Themeable::apply_theme(). apply_theme_attributes() was removed from all Themeable subclasses.
    - Renamed Themeable::replace_all_attributes_with() to Themeable::entangle_with().
    - Renamed Themeable::store_child_themeable_pointer() to Themeable::add_child_themeable_pointer().
    - Window now uses Themeable::assign_tag_prefixes() instead of a special implementation.
    - Themeable::set_functionality_disabled() now propagates to the caller's children.
    - Themeable tags no longer use the 'layers' prefix.
    - Renamed AttributeWidget to AttributeEditor
    - Renamed CustomizePanel to WidgetEditor
    - Renamed CustomizeMenu to ThemeEditor
    - The theme editor now opens up to a widget editor pertaining to the app instead of the window.
    - The app menu is now considered the window's main menu. A main menu is expected to be implemented by Layers app developers.
    - A second window is no longer automatically initialized at launch. When selecting child widgets from the app's widget editor, the widget is cloned before being set as the theme editor's preview widget.
    - The dialogs are now app child widgets.
    - Added icons to the dialogs.
    - Implemented WidgetButton and WidgetButtonGroup classes which improve the design and organization of widget buttons in widget editors.
    - All top-level attribute editors now have a disable toggle switch. The disable toggle switch has been realigned to the top-left corner of attribute editors.
    - Implemented the ThemeableBox class which generalizes functionality that was shared between the Widget class and the various dialog classes.
    - Created the ThemeCompatibilityCautionDialog, which is supposed to alert users when a theme lacks an implementation for the app they are using. This does not mean that they can't apply the theme. If they do, an implementation will be obtained from the last compatible ancestor theme.
    - Implemented the Dialog class which further generalizes the dialog sub-classes
    - Implemented a ScrollBar class that is themeable and customizable
    - Implemented the ColorPlane class which represents a 3D slider of an HSV cylinder. It displays a 2D cross-section of the cylinder and links with an external slider to allow for manipulation of the plane's z-value.
    - Implemented the ColorDialog class which utilizes the new ColorPlane.
    - The FillDialog class was created to separate its logic from the FillControl class.
    - Renamed GradientSelectionDialog to GradientDialog.
    - Transformed the MenuLabelLayer class into the Tab class.
    - Created a new tab bar class to support the new tabs.
    - Created TableView class which provides a themeable table. Several other classes were also created to support tables.
    - Replaced the Layers combobox class with a new one that implements a QComboBox and uses the model-view design pattern.
    - Graphics now support padding.
    - Created SvgRenderer class which provides a new themeable SVG mechanism.
    - Numerous memory leak issues were discovered and patched.
    - Reorganized files and directories. Privatized several classes.
    - init_child_themeable_list() has been replaced with new functionality that allows a Themeable to autonomously generate a list of associated child Themeables. It has been removed from all classes that previously implemented it.

### 3.0.0a (November 29, 2022)
    - The Attribute class now inherits QObject to provide signal/slot functionality.
    - Created a Variant class that wraps a QVariant and inherits QObject to provide signal/slot functionality.
        > Attributes store Variants which are made to be replaceable. An Attribute can replace its Variant with another Attribute's Variant. If either Attribute makes a change to the Variant, both Attributes get updated.
        > When Variants update, it emits Variant::changed, and the Attributes linked to them emit the Attribute::value_changed signal. This mechanism is referred to as attribute value change detection, and it replaces the AttributeSharingCombo. The AttributeSharingCombo class has been deprecated and removed.
    - Previously, when setting an attribute's value, the value would be set without checking if the attribute already had that value. Now it performs that check, resulting in a performance boost and better protection.
    - The AttributeSet class has been removed.
        > Slightly different data structures are now used for storing attributes between Themes and Themeables.
        > Widget attributes are now initialized as public member variables, removing the need to iterate each time an Attribute needs to be referenced.
    - Created Theme::consume(theme) function for applications to add their widget's theme values to the library's default themes
    - Removed issue_update() since widgets can connect update() to Attribute::value_changed.
    - Saving and loading now uses JSON formatting.
    - Changed Variant->ints to Variant->doubles. This change was made due to JSON formatting not differentiating between int and double types
    - The theme building functions have been removed. Changes to the prebuilt themes are made directly in their JSON files.
    - Previously, all CustomizePanels were initialized and acquired when the application was launched. This resulted in a large amount of memory being used which was unnecessary because the user only interacts with a single CustomizePanel at a time. Now, CustomizePanels are generated during runtime as the user navigates the widget hierarchy.
    - Renamed various AttributeWidget classes
    - Created the AttributeGroup and AttributeLayout classes to simplify the creation of AttributeWidgets and specify their organization in CustomizePanels
    - Created a FillControl class that simplifies setting color/gradient values and toggling between them.
    - Created the StateAW (State Attribute Widget) class which provides an improved interface for customizing stateful attributes.
    - The NumberAW (formerly known as NumberAttributeWidget) now utilizes a mini slider and takes up less space.
    - More widgets are customizable:
        > Widgets of the Customize menu's topbar
        > Dialogs
        > ScrollAreas
        > Fixed App Preferences settings panel customizations
    - More widget attributes are customizable:
        > Widget margins
        > Widgets can now be filled with gradients.
        > Fixed outline color and corner color customizations
    - Collapsed text button widget is now a different color to prevent the text buttons from disappearing 
    - Reworked application initialization
        > A GitHubRepo class has been created to clarify that the string argument representing a GitHub repo provided for app initialization is a GitHub repo.
        > A Version class has been created to clarify that the string argument representing the app version provided for app initialization is a Version.
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