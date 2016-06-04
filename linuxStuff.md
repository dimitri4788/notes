GNU Linux Stuff
===============


###Generate a static library (object code archive file)
- Compile: ```gcc -Wall -c ctest1.c ctest2.c```
- Create library "libctest.a": ```ar -cvq libctest.a ctest1.o ctest2.o```
- List files in library: ```ar -t libctest.a```


###Generate a shared object (shared library): (Dynamically linked object library file)
- Create object code: ```gcc -Wall -fPIC -c *.c```
- Create library: ```gcc -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0 *.o```
- ```mv libctest.so.1.0 /opt/lib```
- Optional: create default version using a symbolic link
    - ```ln -sf /opt/lib/libctest.so.1.0 /opt/lib/libctest.so.1```
    - ```ln -sf /opt/lib/libctest.so.1.0 /opt/lib/libctest.so```
- This creates the library libctest.so.1.0 and symbolic links to it

#####Compiler options
- Wall: include warnings. See man page for warnings specified
- fPIC: Compiler directive to output position independent code, a characteristic required by shared libraries. Also see "-fpic"
- shared: Produce a shared object which can then be linked with other objects to form an executable
- Wl,options: Pass options to linker
    - In this example the options to be passed on to the linker are: "-soname libctest.so.1". The name passed with the "-o" option is passed to gcc
- Option -o: Output of operation. In this case the name of the shared object to be output will be "libctest.so.1.0"


###Library Path
In order for an executable to find the required libraries to link with during run time, one must configure the system so that the libraries can be found. Methods available:  
- Add library directories to be included during dynamic linking to the file /etc/ld.so.conf
    - Add the library path to this file and then execute the command (as root) ```sudo ldconfig``` to configure the linker run-time bindings
- Add library and path explicitly to the compiler/linker command: -lname-of-lib -L/path/to/lib
- Specify the environment variable **LD_LIBRARY_PATH** to point to the directory paths containing the shared object library
    - This will specify to the run time loader that the library paths will be used during execution to resolve dependencies


###File Format (for executables, object code, shared libraries, and core dumps; OS: Unix-like)
- **a.out**
    - a.out is a file format used in older versions of Unix-like computer operating systems for executables, object code, and, in later systems, shared libraries
    - The name stands for "assembler output"
    - "a.out" remains the default output file name for executables created by certain compilers and linkers when no output name is specified, even though the created files actually are not in the a.out format
    - The a.out format forced shared libraries to occupy a fixed place in memory. If you wanted to distribute an a.out shared library, you had to register its address space. This was good for performance but it didn't scale at all
        - Linux's transition to ELF was more or less forced due to the complex nature of building a.out shared libraries on that platform, which included the need to register the virtual address space at which the library was located with a central authority, as the a.out ld.so in Linux was unable to relocate shared libraries
- **ELF**
    - The Executable and Linkable Format (ELF, formerly called Extensible Linking Format) is a common standard file format for executables, object code, shared libraries, and core dumps
    - In 1999 it was chosen as the standard binary file format for Unix and Unix-like systems on x86 by the 86open project
    - ELF is flexible and extensible by design, and it is not bound to any particular processor or architecture. This has allowed it to be adopted by many different operating systems on many different platforms
    - In ELF, shared libraries can be loaded anywhere in memory, and can even appear to be at different addresses to different applications running on the same computer (with the code still effectively loaded in only one place in physical memory)! Shared libraries got more complicated in ELF, but that was compiler-side complexity, as opposed to programmer-side


###Tools
- **ar** - create, modify, and extract from archives
- **ranlib** - generate index to archive
- **nm** - list symbols from object files, archive library or shared library
- **ld** - Linker
- **ldconfig** - configure dynamic linker run-time bindings
    - ldconfig -p : Print the lists of directories and candidate libraries stored in the current cache
    - i.e. ```/sbin/ldconfig -p | grep libGL```
- **ldd** - print shared library dependencies
    - Better to use ```objdump -p /path/to/program | grep NEEDED```
        - Reason: Be aware, however that in some circumstances, some versions of ldd may attempt to obtain the dependency information by directly executing the program. Thus, you should never employ ldd on an untrusted executable, since this may result in the execution of arbitrary code
- **objdump** - display information from object files
- **ld.so** - dynamic linker/loader
- **readelf** - displays information about ELF files


Useful reads
------------
####Linker (ld)
- Why does the order in which libraries are linked sometimes cause errors in GCC?
    - http://stackoverflow.com/questions/45135/why-does-the-order-in-which-libraries-are-linked-sometimes-cause-errors-in-gcc

