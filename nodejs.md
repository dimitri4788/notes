Node.js cheatsheet
==================

Node.js is a JavaScript runtime built on Chrome's V8 JavaScript engine. Node.js uses an event-driven, non-blocking I/O model that makes it lightweight and efficient. Node.js' package ecosystem, npm, is the largest ecosystem of open source libraries in the world

It is used to develop I/O intensive web applications like video streaming sites, single-page applications, and other web applications. Node.js is open source, completely free, and used by thousands of developers around the world. It is a platform built on Chrome's JavaScript runtime for easily building fast and scalable network applications. Node.js uses an event-driven, non-blocking I/O model that makes it lightweight and efficient, perfect for data-intensive real-time applications that run across distributed devices.

<hr>
#### Debugging
- Node.js debugging options: <https://spin.atomicobject.com/2015/09/25/debug-node-js/>
- **Node Inspector** is pretty good
    - `$ node-debug <application>`

<hr>
#### Logging
[Winston](https://www.npmjs.com/package/winston)

<hr>
#### Testing
Jasmine, Mocha, Chai, Supertest

<hr>
#### Node.js - REPL (Read Eval Print Loop) Terminal
```sh
$ node
> 1 + 3
4
> x = 10
10
> console.log("Hello World")
Hello World

# ctrl-c twice to quit or ctrl-d once to quit
```

<hr>
#### Node.js - npm (Node Package Manager)
npm provides two main functionalities:

- Online repositories for Node.js packages/modules which are searchable on **search.nodejs.org** or **<https://www.npmjs.com/>**
- Command line utility to install Node.js packages, do version management and dependency management of Node.js packages

See *npm.md* document for more details

<hr>
#### Module Types
Node.js includes three types of modules:

- Core Modules
- Local Modules
- Third Party Modules

The following table lists some of the important core modules in Node.js.

Core Modules | Description
--- | ---
https | http module includes classes, methods and events to create Node.js http server.
url | url module includes methods for URL resolution and parsing.
querystring | querystring module includes methods to deal with query string.
path | path module includes methods to deal with file paths.
fs | fs module includes classes, methods, and events to work with file I/O.
util | util module includes utility functions useful for programmers.

<hr>
#### Commands
Commands | Explanation
--- | ---
`$ node <application-file-name>` | Execute the application
`$ node debug <application-file-name>` | Debug the application <https://nodejs.org/api/debugger.html>
`$ node --trace-sync-io <application-file-name>` | Print a stack trace whenever synchronous I/O is detected after the first turn of the event loop

<hr>
#### Upgrade Node.js via NPM
```
$ sudo npm cache clean -f
$ sudo npm install -g n
$ sudo n stable

# Once your installation is complete, you can confirm your version with:
$ node -v
```

<hr>
#### Useful resources
- [Node.js Best Practices](https://www.codementor.io/mattgoldspink/tutorials/nodejs-best-practices-du1086jja)
- [Advanced, production process manager for Node.js](http://pm2.keymetrics.io/)
- [Secure Express apps by setting various HTTP headers](https://github.com/helmetjs/helmet)

#### Sources
- https://nodejs.org/en/
- https://www.tutorialspoint.com/nodejs/index.htm
- http://www.tutorialsteacher.com/nodejs/nodejs-modules
- https://www.npmjs.com/
