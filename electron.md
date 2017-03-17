Electron
========

- It is a library that is used to build desktop applications with JavaScript, HTML and CSS
- These applications can be packaged to run on Mac, Windows and Linux computers as well as be placed in the Mac and Windows app stores
- Electron combines Chromium and Node.js with a set of custom APIs for native operating system functions like open file dialogs, notifications, icons and more
- Electron = Chromium + Node.js + Native APIs
- Electron has two types of processes: **Main** and **Renderer**
    - There are modules that work on each or in both of the processes
    - The main process is more behind-the-scenes while the renderer process is each of the windows in your app
- **Main Process**
    - The main process (commonly a file named main.js) is the entry point to every Electron app
    - It controls the life of the app, from open to close. It also calls the native elements and creates each new renderer process in the app
    - Common tasks:
        - Create Renderer Processes
        - Call native elements
        - Start and quite app
- **Renderer Process**
    - The renderer process is a browser window in your app
    - Unlike the main process, there can be multiple of these and each is independent; every renderer process is a separate process, meaning a crash in one won't affect another
    - They can also be hidden; you can set a window to be hidden and use it to just execute code in the background
    - Usually one is named index.html
    - They are like typical HTML files but in Electron you've got the whole Node API available here, too, unlike any web browser
    - Use main process modules from the renderer process using `remote` module: <http://electron.atom.io/docs/api/remote/>
    - Common tasks:
        - Design your page with HTML and CSS
        - JavaScript page interations
- Easier way to think: *In Chrome (or another web browser) each tab and its web page is like a single renderer process in Electron. If you close all of the tabs, Chrome is still there, this is like your main process, and you can open a new window or quit the app*
- IPC
    - The main and renderer processes can communicate via IPC, interprocess communication. Use it to pass messages between main and renderer processes
    - The main process and renderer process each have an IPC module to use

#### Summary
Electron apps are like Node apps and use a package.json file. It's there that you define which file is your main process and thus where Electron should start your app. Then that main process can create renderer processes and you'll use IPC to pass messages between the two

## Packaging and Distribution
Once your app is built, you can package it with the command-line tool `electron-packager` for Mac, Windows or Linux. Add scripts for this to your package.json
<https://github.com/electron-userland/electron-packager>

A complete solution to package and build a ready for distribution Electron app with “auto update” support out of the box <https://github.com/electron-userland/electron-builder>

## CSS Variables
CSS variables, also known as CSS custom properties. They can be useful for reducing repetition in CSS, and also for powerful runtime effects like theme switching and potentially extending/polyfilling future CSS features.  
<https://developers.google.com/web/updates/2016/02/css-variables-why-should-you-care?hl=en>

## Development Tools
- [Electron DevTools Extension](http://electron.atom.io/devtron/)
- [Spectron: Electron Testing Framework](http://electron.atom.io/spectron/)

## List of things to make Electron app feel native and pro
- Dock and tray integration
- Notifications
- Menus
- Shortcuts
- Drag and drop
- Crash reporting
- Signed installers
- Automatic updaters
- Fast startup
- One-step build

#### Useful Links
- [Electron API List](http://electron.atom.io/docs/api/)
- [Electron Documentation](http://electron.atom.io/docs/)
- [Electron API Demos](https://github.com/electron/electron-api-demos)
- [Essential Electron](http://jlord.us/essential-electron/)
- [Photon](http://photonkit.com/)
- [Awesome Electron](https://github.com/sindresorhus/awesome-electron)
- [How To Make Your Electron App Sexy](https://blog.dcpos.ch/how-to-make-your-electron-app-sexy)
