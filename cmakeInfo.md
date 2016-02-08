CMake helpful stuff
===================

Some useful stuff to deal with the awesome software development tool: CMake.

Writing module files
--------------------
CMake comes with numerous modules that aid in finding various well-known libraries and packages. You can get a listing of which modules your version of CMake supports by typing cmake --help-module-list, or by figuring out where your modules-path is and looking inside of it. On Ubuntu linux, for example, the module path is /usr/local/Cellar/cmake/**version**/share/cmake/Modules

Command-line:
```sh
cmake --help-module-list
cmake --help-module FindGTest
```

You can write new modules using: pkg-config. Read the How_To_Find_Libraries link from below. Example command:
```sh
pkg-config --libs /usr/local/Cellar/sqlite/3.8.8.3/lib/pkgconfig/sqlite3.pc
```

<br>

CMake Useful Variables
----------------------
- http://www.vtk.org/Wiki/CMake_Useful_Variables

<br>

Output
------
- Verbose output: `make VERBOSE=1`

<br>

enable_testing()
----------------
- Enables testing for this CMake project. This should only be used in top level CMakeLists.txt. The main thing this does is enable the add_test() command.
- This function also adds the "test" target to our Makefile. Making the "test" target will run CTest which will, in turn, run all of our tests.


Sources
-------
- http://www.cmake.org/Wiki/CMake:How_To_Find_Libraries
- http://people.freedesktop.org/~dbn/pkg-config-guide.html
