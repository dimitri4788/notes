npm cheatsheet
==============

`npm` (Node.js Package Manager) makes it easy for JavaScript developers to share and reuse code, and it makes it easy to update the code that you're sharing

`npm` provides two functionalities:

- online repositories for Node.js packages/modules which are searchable on search.nodejs.org
- command line utility to install Node.js packages, do version and dependency management of Node.js packages

#### Global vs Local Installation
npm has two modes of operation:

- global mode:
    - npm installs packages into the install prefix at **prefix/lib/node_modules** and bins are installed in **prefix/bin**.
    - Such dependencies can be used in CLI (Command Line Interface) function of any Node.js but cannot be directly imported using require() in Node.js application
- local mode:
    - npm installs packages into the current project directory, which defaults to the current working directory. Packages are installed to **./node_modules**, and bins are installed to **./node_modules/.bin**.
    - Locally installed packages are accessible via require() method

NOTE: Local mode is the default. Use -g or --global on any command to operate in global mode instead.

#### package.json
- package.json is present in the root directory of every Node.js application/module and is used to define the properties of a package
- Attributes of package.json
    - *name*: name of the package
    - *version*: version of the package
    - *description*: description of the package
    - *homepage*: homepage of the package
    - *author*: author of the package
    - *contributors*: name of the contributors to the package
    - *dependencies*: list of dependencies. npm automatically installs all the dependencies mentioned here in the node_modules directory of the package
    - *repository*: repository type and URL of the package
    - *main*: entry point of the package
    - *keywords*: keywords

#### Commands
Commands | Explanation
--- | ---
`$ npm install <moduleName>` | Install a module locally (your current Node.js application directory)
`$ npm install <moduleName> -g` | Install a module globally (system directory)
`$ npm uninstall <moduleName>` | Uninstall a module
`$ npm update <moduleName>` | Update a module
`$ npm search <moduleName>` | Search a module
`$ npm ls` | Lists all the locally (your current Node.js application directory) installed modules
`$ npm ls -g` | Lists all the globally (system directory) installed modules
`$ npm -v` | Print npm version
`$ npm install npm@latest -g` | Update npm
`$ npm help` | List of available commands









Sources
-------
- https://docs.npmjs.com/
