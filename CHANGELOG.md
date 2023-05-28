# Changelog

All notable changes to this project will be documented in this file.

## [Unreleased]

### Added

- Implemented the Data class which stores either a single variant or a map of state-variant pairs.
- Implemented the AbstractAttribute class which now serves as the abstract parent class of Attribute and AttributeGroup.
- Implemented theme file separation and theme directories.
- Implemented theme meta-loading. When an application is launched, instead of fully loading all the themes, only their metadata is loaded. Only the active theme is fully loaded.
- Added icons to the dialogs.
- Implemented WidgetButton and WidgetButtonGroup classes which improve the design and organization of widget buttons in widget editors.
- Implemented the ThemeableBox class which generalizes functionality that was shared between the Widget class and the various dialog classes.
- Implemented the Dialog class which further generalizes the dialog subclasses.
- Implemented the ThemeCompatibilityCautionDialog which is supposed to alert users when a theme lacks an implementation for the app they are using. This does not mean that they can't apply the theme. If they do, an implementation will be obtained from the last compatible ancestor theme.
- Implemented a ScrollBar class that is themeable and customizable.
- Implemented the ColorPlane class which serves as a two-dimensional slider for selecting a color from an HSV cylinder. It displays a cross-section of the cylinder and can be linked with an external slider to allow for manipulation of the plane's z-value.
- Implemented the ColorDialog class which utilizes the new ColorPlane.
- Implemented the FillDialog class to separate its logic from the FillControl class.
- Implemented a new TabBar class that replaces the MenuLabelLayer class.
- Implemented TableView class which provides a themeable table.
- Implemented SvgRenderer class which provides a new themeable SVG mechanism.
- Implemented the Navigator class which utilizes buttons that label a hierarchy of items, allowing the user to navigate between the items in the hierarchy.
- Implemented RadioButton class.
- Implemented RadioButtonPool class which helps to ensure that only one radio button in a collection can be enabled at a time.

### Changed

- Renamed several classes and functions:
    - Window ➔ MainWindow
    - Titlebar ➔ MainWindowTitlebar
    - CustomizeMenu ➔ ThemeEditor
    - CustomizePanel ➔ WidgetEditor
    - AttributeWidget ➔ AttributeEditor
    - GradientSelectionDialog ➔ GradientDialog
    - Application::current_theme() ➔ Application::active_theme()
    - Themeable::replace_all_attributes_with() ➔ Themeable::entangle_with()
    - Themeable::store_child_themeable_pointer() ➔ Themeable::add_child_themeable_pointer()
    - AbstractAttribute::value_changed() ➔ AbstractAttribute::changed()
- Applications and themes now use UUIDs to prevent name-clash.
- Attribute groups are now recognized by themes.
- Attribute groups are now disableable.
- The term 'entangle' is now used to describe the action of forcing one attribute to discard its data and use the data of another attribute.
- Capitalized attribute names are now derived.
- Attribute now emits value_changed() if the state is set.
- Member attributes are now private with public access functions.
- Themes are now stored in the ".../AppData/Local/Layers" directory which has been reinstated to aid multiple app support for themes.
- The functionality to load theme implementation files has been moved from the Theme constructor into a separate member function, Theme::load_document(). It can be called multiple times to load multiple implementation files into a single Theme instance.
- Default themes are now stored in theme directories identified by resource files.
- Theme lineage is now tracked with theme metadata. 
- MainWindow now uses Themeable::assign_tag_prefixes() instead of an override implementation.
- Themeable::set_functionality_disabled() now propagates to the caller's children.
- The theme editor now opens up to a widget editor pertaining to the app instead of the window.
- A second window is no longer automatically initialized at launch. When selecting child widgets from the app's widget editor, another instance of the child widget is initialized and set as the theme editor's preview widget.
- The dialogs are now app child widgets.
- All top-level attribute editors now have a disable toggle switch. The disable toggle switch has been realigned to the top-left corner of attribute editors.
- Replaced the Layers combobox class with a new one that implements a QComboBox subclass and uses the model-view design pattern.
- Graphics now support padding.
- Reorganized files and directories. Privatized several classes.
- init_child_themeable_list() has been replaced with new functionality that allows a Themeable to autonomously generate a list of associated child Themeables.
- The Graphic class has been reworked to incorporate the functionality of the ImageSequenceLabel class and make use of the SvgRenderer class.
- Simplified how multi-valued attributes are stored in theme files.
- Simplified how gradients are stored in theme files.
- The Application will now load any fonts found in the ":/fonts" resource directory.
- GitHubRepo can now be constructed using either a full URL or shortened one.
- The minimum size suggestion is now 40px instead of 45px. It works better as an even number, and the smaller size will allow for more widgets to fit together in smaller spaces. This has been updated throughout the library.
- Simplified the calculation for the inner-radius of borders with rounded corners.

### Fixed

- Fixed an issue where themeables connected to multi-valued attributes didn't update properly when their state changed.
- Numerous memory leak issues were discovered and patched.

### Removed

- Removed the SVG class in favor of the SvgRenderer class.
- Removed the ImageSequenceLabel class since its functionality is now handled by the Graphic class.
- Removed Theme::consume() in favor of Theme::load_document().
- Removed Theme::copy().
- Removed Themeable::apply_theme_attributes() from all Themeable subclasses. A generic version is now included in Themeable::apply_theme().
- Removed the 'layers' prefix from themeable tags.
- Removed corner color, hover fill, and outline color attributes from ThemeableBox due to low usage.
- Removed auto_touch_target_compliance parameter from Button constructors. Minimum sizing will be a suggestion from now on.

## [0.15.0] - 2022-11-29

### Added

- Created a Variant class that wraps a QVariant and inherits QObject to provide signal/slot functionality.
    - Attributes store variants which are made to be replaceable. An attribute can replace its variant with the variant of another attribute. If either attribute makes a change to the variant, both attributes get updated.
    - When the value of a variant is updated, it emits Variant::changed, and the attributes linked to it emit the Attribute::value_changed signal. This mechanism is referred to as value change detection, and it replaces the functionality of the AttributeSharingCombo.
- Created Theme::consume() function for Layers app developers to add their theme data to the library's default themes.
- Created the AttributeGroup and AttributeLayout classes to simplify the creation of attribute widgets and specify their organization in customize panels.
- Created the FillControl class which simplifies setting color/gradient values and toggling between them.
- Created the StateAW (State Attribute Widget) class which provides an improved interface for customizing stateful attributes.
- Created a GitHubRepo class to clarify that the string argument representing a GitHub repo provided for app initialization is a GitHub repo.
- Created a Version class has been created to clarify that the string argument representing the app version provided for app initialization is a version.
- Created MenuBar and TabBar classes.
- More widgets are customizable:
    - Widgets of the customize menu's topbar
    - Dialogs
    - Scroll areas
- Widget margins are now customizable.
- Widgets can now be filled with gradients.

### Changed

- The Attribute class now inherits QObject to provide signal/slot functionality.
- When setting an attribute's value, a check if performed to determine if the attribute already has that value, resulting in a performance boost.
- Widget attributes are now initialized as member variables, removing the need to iterate each time an attribute needs to be referenced.
- Themes are now stored in JSON format.
- Changed variants with integer values to variants with double values. This change was made due to JSON formatting not differentiating between int and double types.
- Previously, the customize panels for all themeable widgets were initialized and acquired when the application was launched. This resulted in a large amount of memory being used which was unnecessary because the user only interacts with a single customize panel at a time. Now, customize panels are generated during runtime as the user navigates the widget hierarchy.
- Renamed various AttributeWidget classes.
- The NumberAW (formerly known as NumberAttributeWidget) now utilizes a mini slider and takes up less space.
- Image sequences can now be stored as a single file.
- The text of combo box items is no longer editable by default.
- Button text can word-wrap now after defining an available width limit.

### Fixed

- Fixed App Preferences settings panel customizability.
- Fixed outline color and corner color customizability.
- Fixed customize menu text buttons visibility when collapsed.
- Fixed some issues where the preview window had too much functionality enabled.

### Removed

- The AttributeSharingCombo has been removed.
- The AttributeSet class has been removed. Slightly different data structures are now used for storing attributes in themes and themeables.
- Removed issue_update() since widgets can connect update() to Attribute::value_changed.
- The functions that generated the default themes have been removed. Changes to the default themes can now be made directly in their JSON files.

## [0.14.0] - 2021-09-11

### Added

- Created a mechanism to update the application during start up. For now, this only works for applications hosted on GitHub.

### Changed

- Upgraded to Qt 6.
- Application settings are now stored in the registry system.
- The active theme is now applied automatically when the application is launched again.
- Prebuilt themes are now packaged with the application and not stored in the app's theme folder.

### Fixed

- Fixed an issue with the theme updating functionality that caused themes from old versions to be missing attribute sets and attributes for widgets created in later versions.

## [0.13.0] - 2021-09-01

### Added

- Created a mechanism to update themes. Themes created in 0.12.0 will continue to work in this version.
- Created a mechanism to collapse text buttons in the customize menu's topbar.

### Changed

- The corner radii attribute widget has been redesigned and takes up less space.
- Themes are no longer stored in a universal Layers directory. Instead, each application stores its own set of themes in a folder pertaining to the application.

### Removed

- Removed the 'Default' and 'Common' states. Attributes are now created as stateful or stateless. This makes customization of themeables that use both types of attributes much clearer.

## [0.12.0] - 2021-06-23

### Added

- Added support for rounded corners. Many widgets now use rounded corners by default.

### Changed

- Layers has been rewritten. Some functionality that was present in previous versions is missing from this one and might not return.
- The Widget_Wrapper class has been redesigned and renamed to Themeable.
- Most buttons and controls have increased padding around their content and increased spacing to improve the touch experience.
- Theme swapping and customization application are now instant.
- Widget attributes are now applied via paint events instead of invoking stylesheets.
- Pop-up boxes are now separate windows.
- Reworked the customize menu:
    - Expanded customization to all widgets that inherit Themeable.
    - Improved widget hierarchy navigation.

## [0.11.0] - 2020-04-20

### Added

- Added an "Apply" button in the Customize menu that allows you to apply your customizations to the current theme of the main window.
- Added theme saving which occurs automatically when themes are created and when customizations have been applied.

### Changed

- Changed New theme button to be graphic only; changed its graphic to be a plus symbol and moved it to the left of the Theme combobox.
- Moved the Customize button out of the Theme combobox and placed the button to the right of the combobox.
- Changed Delete theme button to be graphic only and moved it to the right of the Customize button.
- The New theme button is now functional.
- The Delete theme button is now functional.
- The New and Delete theme buttons are only enabled when a non-built-in theme is applied.
- Editing the theme name is disabled for built-in themes.
- Changing the theme name is now done by double clicking on the Theme combobox where it will temporarily turn into a line edit.

### Removed

- Removed the "Save" and "Save As..." buttons from the Themes settings panel and will automatically save themes when they are created and when customizations have been applied.

## [0.10.3] - 2020-04-11

### Added

- Created CheckBox class.

### Changed

- Changed the Royal Blue and Purple themes' darker color to be even darker for improved contrast.
- Changed the Light theme's text color in various places to be darker for improved contrast.

## [0.10.2] - 2020-04-06

### Fixed

- Fixed an issue where app menu widgets' options panels weren't being themed.

## [0.10.1] - 2020-04-05

### Changed

- Changed icons for the App Menu, Settings Menu, and Customize Menu widget buttons within the Customize menu to match what their menus use in the Menu Label Layers.

## [0.10.0] - 2020-04-02

### Added

- More widgets are customizable:
    - Customize Menu
    - Message Boxes

### Changed

- Changed the default border thickness of message boxes from 7px to 10px.

### Fixed

- Fixed a small issue where certain widgets' hover gradients were not theming properly.
- Fixed over-generation issue that led to slowdowns and a major memory usage increase. This fix significantly improved performance.

## [0.9.0] - 2020-03-30

### Added

- Navigating through the widget hierarchy in the Customize menu now auto-navigates the preview window to ensure the user is viewing the widget being editted.
- More widgets are customizable:
    - Themes Settings Panel

### Fixed

- Small issue where a pile of small windows would appear then disappear during startup.

## [0.8.0] - 2020-03-28

### Added

- More widgets are customizable:
    - App Preferences Settings Tab
    - App Preferences Settings Panel
    - Themes Settings Tab
    - Themes Settings Panel (WIP)

## [0.7.0] - 2020-03-27

### Added

- More widgets are customizable:
    - Titlebar

### Changed

- The color display widget now displays a default color picker when clicked. Line edits that were in place next to color displays have been removed in favor of using the color picker.

## [0.6.0] - 2020-03-25

### Added

- More widgets are customizable:
    - Titlebar (WIP)
    - Window Border (More customizable attributes)

### Changed

- Changed the window title label from bold to normal.
- Changed the window size to 870x630

## [0.5.0] - 2020-03-24

### Added

- Added version labels in 'App Preferences' page of the settings menu.
- Created a new gradient selection widget.
- More widgets are customizable:
    - Themes Settings Panel (WIP)
    - Window Border (More customizable attributes)

## [0.4.0] - 2020-03-22

### Added

- Created labeled toggle switches which have a label on each end.
- More widgets are customizable:
    - Settings Menu (WIP)
    - Window Border (WIP)

### Changed

- The light and dark themes now use a gradient for the window border by default.

## [0.3.0] - 2020-03-20

### Added

- Added copy operations to the main window and its child objects
- Began work on the Customize menu
    - Created the layout for navigating the widget hierarchy that displays the proper options on the Customize menu's sidebar. As you go down the hierarchy from the "Window", a set of labels are displayed above the preview window to inform the user specifically which widget they are manipulating. These labels are also buttons that allow the user to return to widgets up the hierarchy.
    - The first customizable attribute in this release is the Titlebar's color. However, there is no structure yet to handle applying the theme changes to the main window, so changes are not permanent.
- Option to recursively disable primary functionality of the main window (intended for the Customize menu's copy of the window).

### Changed

- Changed the "Window Border" button in the Themes settings panel to a button with a wrench icon located within the Themes combobox used to universally access the Customize menu.

### Removed

- Removed the temporary Square and Circle settings tabs/panels.

## [0.2.0] - 2020-02-16

### Added

- Layers-specific settings can now be saved. The settings file is found in:
    ".../AppData/Local/Layers"
    - Fow now, the only layers setting is the default theme setting
- Application-specific settings can now be saved. The settings file is found in:
    ".../AppData/Local/Layers/{Application Name}"
    - Now the theme you set for an application is reapplied when you relaunch the application.
- Created MessageBox class
- Added "Set as default" button within the theme combobox. Clicking this will present a confirmation message box to set the default theme. Other Layers applications will use the default theme until the user changes that application's theme manually using the theme combobox.

### Changed

- Overhauled the theming system:
    - Most changes are structural and do not change the visual appearance of the widgets.
    - Scrollbar theming is working now.
- Changed some colors in the Royal Blue and Purple themes.
- Adjusted spacing of widgets in Themes settings panel.

### Fixed

- Fixed font inconsistencies.
- The text in the theme name line edit within the themes settings panel now updates to the theme name upon switching themes. However, changing the text in the line edit does not affect the theme, yet.

## [0.1.1] - 2019-12-21

### Fixed

- Fixed window moving with the cursor after minimizing and restoring.
- Fixed maximizing causing the normal window size to change.
- Fixed an issue where you could click-drag on buttons on the titlebar and move the window.

## [0.1.0] - 2019-12-18

### Added

- This release serves as the first versioning tag for this software. The following points briefly cover the features currently implemented:
    - A window-scaling border
    - A theming system
    - SVG support
    - A menuing/sub-menuing system
    - A menu navigation and labeling system
    - A settings menu accessible via a titlebar icon