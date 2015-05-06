## Static and Dynamic Libraries

- Static libraries (.a): Library of object code which is linked with, and becomes part of the application.
    - Static libraries are also known as static archive libraries and static linked shared libraries.
- Dynamic libraries (.so): There is only one form of this library but it can be used in two ways.
    - Dynamically linked at run time but statically aware. The libraries must be available during compile/link phase. The shared objects are not included into the executable component but are tied to the execution.
    - Dynamically loaded/unloaded and linked during execution (i.e. browser plug-in) using the dynamic linking loader system functions.
    - Dynamic libraries are also known as dynamic shared libraries, shared objects, or dynamically linked libraries.

### Sources
- http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html
- https://developer.apple.com/library/mac/documentation/DeveloperTools/Conceptual/DynamicLibraries/100-Articles/OverviewOfDynamicLibraries.html
- http://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
- http://stackoverflow.com/questions/7096152/c-difference-between-linking-library-and-adding-include-directories
- http://stackoverflow.com/questions/1033898/why-do-you-have-to-link-the-math-library-in-c
