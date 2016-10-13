npm cheatsheet
==============

`npm` (Node.js Package Manager) makes it easy for JavaScript developers to share and reuse code, and it makes it easy to update the code that you're sharing

`npm` provides two functionalities:

- online repositories for Node.js packages/modules which are searchable on search.nodejs.org
- command line utility to install Node.js packages, do version and dependency management of Node.js packages

#### npmrc (The npm config files)
- `npm` gets its config settings from the command line, environment variables, and npmrc files.
- The npm config command can be used to update and edit the contents of the user and global npmrc files.
- FILES
    - The four relevant files are:
        - per-project config file (/path/to/my/project/.npmrc)
        - per-user config file (~/.npmrc)
        - global config file ($PREFIX/etc/npmrc)
        - npm builtin config file (/path/to/npm/npmrc)

#### Global vs Local Installation
`npm` has two modes of operation:

- global mode:
    - `npm` installs packages into the install prefix at **prefix/lib/node_modules** and bins are installed in **prefix/bin**.
    - Such dependencies can be used in CLI (Command Line Interface) function of any Node.js but cannot be directly imported using require() in Node.js application
- local mode:
    - `npm` installs packages into the current project directory, which defaults to the current working directory. Packages are installed to **./node_modules**, and bins are installed to **./node_modules/.bin**
    - Locally installed packages are accessible via require() method

NOTE: Local mode is the default. Use -g or --global on any command to operate in global mode instead

#### package.json
- package.json is present in the root directory of every Node.js application/module and is used to define the properties of a package
- Attributes of package.json
    - *name*
        - name of the package
    - *version*
        - version of the package
    - *description*
        - description of the package; it's a string
        - this helps people discover your package, as it's listed in `npm` search
    - *homepage*
        - url to the project homepage
    - *author*
        - author of the package
    - *contributors*
        - name of the contributors to the package
    - *dependencies*
        - list of dependencies. `npm` automatically installs all the dependencies mentioned here in the node_modules directory of the package
    - *repository*
        - specify the place where your code lives
        - This is helpful for people who want to contribute. If the git repo is on GitHub, then the `npm` docs command will be able to find you
        - for example, "repository" : { "type" : "git" , "url" : "https://github.com/npm/npm.git" }
    - *main*
        - entry point of the package
        - the main field is a module ID that is the primary entry point to your program. That is, if your package is named foo, and a user installs it, and then does require("foo"), then your main module's exports object will be returned
        - this should be a module ID relative to the root of your package folder
        - for most modules, it makes the most sense to have a main script and often not much else
    - *bin*
        - a lot of packages have one or more executable files that they'd like to install into the PATH. `npm` makes this pretty easy (in fact, it uses this feature to install the "npm" executable.)
        - for example, myapp could have this: { "bin" : { "myapp" : "./cli.js" } }
    - *man*
        - specify either a single file or an array of filenames to put in place for the `man` program to find
        - { "name" : "foo" , "version" : "1.2.3" , "description" : "A packaged foo fooer for fooing foos" , "main" : "foo.js" , "man" : "./man/doc.1" }
    - *keywords*
        - keywords; put keywords in it. It's an array of strings
        - this helps people discover your package as it's listed in `npm search`
    - *license*
        - specify a license for your package so that people know how they are permitted to use it, and any restrictions you're placing on it
    - *bugs*
        - url to the project's issue tracker and / or the email address to which issues should be reported
        - these are helpful for people who encounter issues with your package
    - *files*
        - this field is an array of files to include in your project
        - if you name a folder in the array, then it will also include the files inside that folder
        - you can also provide a ".npmignore" file in the root of your package or in subdirectories, which will keep files from being included, even if they would be picked up by the files array
        - the .npmignore file works just like a .gitignore
        - Certain files are always included, regardless of settings
            - package.json
            - README (and its variants)
            - CHANGELOG (and its variants)
            - LICENSE / LICENCE
- Most important things in package.json are the *name* and *version* fields. Those are required, and your package won't install without them
- The name and version together form an identifier that is assumed to be completely unique
- The *package.json* file defines the package. The *node_modules* folder is the place Node.js looks for modules
    - For example, if you create a file at *node_modules/foo.js* and then had a program that did `var f = require('foo.js')`, it would load the module. However, foo.js is not a "package" in this case, because it does not have a package.json.

#### What is a package?
A package is any of:

- a folder containing a program described by a package.json file
- a gzipped tarball containing (a)
- a url that resolves to (b)
- a <name>@<version> that is published on the registry with (c)
- a <name>@<tag> that points to (d)
- a <name> that has a latest tag satisfying (e)
- a git url that, when cloned, results in (a).

#### What is a module?
A module is anything that can be loaded with require() in a Node.js program. The following are all examples of things that can be loaded as modules:

- A folder with a package.json file containing a main field.
- A folder with an index.js file in it.
- A JavaScript file

Generally, `npm` packages that are used in Node.js program are loaded with require, making them modules. However, there's no requirement that an `npm` package be a module.

Some packages, e.g., cli packages only contain an executable command-line interface, and don't provide a main field for use in Node.js programs. These packages are not modules.

#### Commands
Commands | Explanation
--- | ---
`$ npm install <moduleName>` | Install a local module
`$ npm install <moduleName> -g` | Install/Update a global module
`$ npm uninstall <moduleName>` | Uninstall a module
`$ npm update <moduleName>` | Update a module
`$ npm update -g` | Update all global packages
`$ npm update` | Update locak packages (in the same directory as your package.json file)
`$ npm install -g <package>` | Update a global package
`$ npm outdated -g --depth=0` | find out which packages need to be updated
`$ npm search <moduleName>` | Search a module
`$ npm ls` | Lists all the locally (your current Node.js application directory) installed modules
`$ npm ls -g` | Lists all the globally (system directory) installed modules
`$ npm -v` | Print npm version
`$ npm install npm@latest -g` | Update npm
`$ npm help` | List of available commands
`$ npm list` | List all the versions of packages that are installed, as well as their dependencies, in a tree-structure

Sources
-------
- https://docs.npmjs.com/
- https://docs.npmjs.com/files/package.json
