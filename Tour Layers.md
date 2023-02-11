# Tour Layers

[TOC]

After you launch the Layers Demo, you will be presented with a nearly empty window.

![Screenshot of Layers Demo](demo_dark.svg)

## Window

The window is laid out with a **titlebar** at the top and the active **menu** underneath it. The first active menu is called the **main menu**.

![Window Layout Image](window_layout.svg)

### Titlebar

The titlebar contains a tab bar on the left and a set of buttons on the right.

![Titlebar Layout Image](titlebar_layout.svg)

#### Tab Bar

The tabs on the titlebar's tab bar represent the menus that have been opened.

![Tab Bar Image](tab_bar.svg)

The first tab is associated with the window's main menu, and it is a special tab since it is both constrained to the far left of the tab bar and missing an exit button because the main menu is not exitable. The first tab also serves to label the window.

#### Buttons

You should already be familiar with most of the titlebar buttons.

![Titlebar Buttons Image](titlebar_buttons.png)

**From right to left:**

There is an **exit button**, which exits the window or the entire app if the window being closed is the main window.

There is a **maximize button**, which fullscreens the window, and then there is a **minimize button**, which hides it.

The last button is the **setting button**, which opens the settings menu. Almost every software application provides a menu where settings can be changed by the user. Layers simplifies this by providing a settings menu for the developer where they can integrate their settings with the settings that are included with Layers, such as theme settings.

### Main Menu

The Layers app developer is responsible for implementing the window's main menu, which is supposed to house a majority of the developer's implemented app functionality. Once the developer sets a main menu, the window automatically opens it, making it the first active menu.

The Layers Demo has an empty main menu. This is because the demo does not implement any app functionality. It is meant to be a minimal Layers app, with the binary release serving to demonstrate the capabilities of the Layers, and the source code serving to provide Layers app developers with a starting template.

### Settings Menu

The settings menu is accessible by clicking on the settings button found on the titlebar.

\htmlonly
<video style="max-width:100%;height:auto;" width="1220" height="820" loop muted disableRemotePlayback>
    <source src="open_settings_menu.mp4" type="video/mp4">
    Your browser does not support the video tag.
</video>
\endhtmlonly

The settings menu has its own set of tabs on the sidebar to the left. The right side of the menu displays the active settings panel.

#### Themes Settings Panel

Layers includes a single settings panel called the themes settings panel.

##### Applying the Active Theme

The themes panel includes a combo box which lets the user apply the active theme. Layers has two default themes, the Dark and Light themes.

\htmlonly
<video style="max-width:100%;height:auto;" width="1220" height="820" loop muted disableRemotePlayback>
    <source src="change_theme.mp4" type="video/mp4">
    Your browser does not support the video tag.
</video>
\endhtmlonly

##### Create a Custom Theme

Underneath the theme combo box, there is a button with a plus icon, the **create theme button**. Clicking this button opens a dialog that lets the user create a custom theme. The dialog contains a line editor where the user can enter the name of their new theme, as well as a combo box that lets the user pick the theme that is copied to start the new one.

\htmlonly
<video style="max-width:100%;height:auto;" width="1220" height="820" loop muted disableRemotePlayback>
    <source src="create_new_theme.mp4" type="video/mp4">
    Your browser does not support the video tag.
</video>
\endhtmlonly

##### Custom Theme Options

Custom themes include a few more options than the default ones. Underneath the theme combo box, there are two additional buttons that are only visible when the active theme is a custom, the **customize button** and the **delete button**.

Clicking on the customize button opens the customize menu, which is a menu designed for customizing themes.

Clicking on the delete button deletes the theme.

Renaming the theme is an additional feature that only pertains to custom themes. However, the way that you rename a theme is not obvious: You must double-click on the theme combo box while the custom theme is active. This will temporarily turn the combo box into a line editor, allowing the user to enter a new name.

\htmlonly
<video style="max-width:100%;height:auto;" width="1220" height="820" loop muted disableRemotePlayback>
    <source src="rename_theme.mp4" type="video/mp4">
    Your browser does not support the video tag.
</video>
\endhtmlonly


\htmlonly
<script>
    let options = {
        root: null,
        rootMargin:'0px',
        threshold:0.6
    };
    let callback = (entries, observer)=>{
        entries.forEach(entry => {
            if(entry.target.tagName == "VIDEO")
            {
                if(entry.isIntersecting) {
                    entry.target.play();
                }
                else {
                    entry.target.pause();
                }
            }
        });
    }
    let observer = new IntersectionObserver(callback, options);

    const videos = document.querySelectorAll('video');

    for (let i = 0; i < videos.length; i++) {
      observer.observe(videos[i]);
    }
</script>
\endhtmlonly
