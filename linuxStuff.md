GNU Softwares
=============


Generate a static library (object code archive file)
----------------------------------------------------
- Compile: ```gcc -Wall -c ctest1.c ctest2.c```
- Create library "libctest.a": ```ar -cvq libctest.a ctest1.o ctest2.o```
- List files in library: ```ar -t libctest.a```

Generate a shared object (shared library): (Dynamically linked object library file)
------------------------------------------------------------------------------------
- Create object code: ```gcc -Wall -fPIC -c *.c```
- Create library: ```gcc -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0 *.o```
- ```mv libctest.so.1.0 /opt/lib```
- Optional: create default version using a symbolic link
    - ln -sf /opt/lib/libctest.so.1.0 /opt/lib/libctest.so.1
    - ln -sf /opt/lib/libctest.so.1.0 /opt/lib/libctest.so
- This creates the library libctest.so.1.0 and symbolic links to it

#####Compiler options
- Wall: include warnings. See man page for warnings specified.
- fPIC: Compiler directive to output position independent code, a characteristic required by shared libraries. Also see "-fpic".
- shared: Produce a shared object which can then be linked with other objects to form an executable.
- Wl,options: Pass options to linker. 
    In this example the options to be passed on to the linker are: "-soname libctest.so.1". The name passed with the "-o" option is passed to gcc.
- Option -o: Output of operation. In this case the name of the shared object to be output will be "libctest.so.1.0"






Useful reads
------------
####Linker (ld)
- Why does the order in which libraries are linked sometimes cause errors in GCC?
    - http://stackoverflow.com/questions/45135/why-does-the-order-in-which-libraries-are-linked-sometimes-cause-errors-in-gcc

