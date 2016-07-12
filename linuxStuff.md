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
    - PIC stands for position-independent code. The functions in a shared library may be loaded at different addresses in different programs, so the code in the shared object must not depend on the address (or position) at which it is loaded. This consideration has no impact on you, as the programmer, except that you must remember to use the -fPIC flag when compiling code that will be used in a shared library
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


###Compilation and Execution
- Compilation can involve up to four stages:
    - **Preprocessing** (cpp)
        - Text Substitution
        - Stripping of Comments
        - File Inclusion
    - **Compilation proper** (cc/gcc)
    - **Assembly** (as)
    - **Linking** (ld)
- GCC is capable of preprocessing and compiling several files either into several assembler input files, or into one assembler input file; then each assembler input file produces an object file, and linking combines all the object files (those newly compiled, and those specified as input) into an executable file
- Example
    - Given a source file: hello.c
    - ```cpp hello.c > hello.i```
        - or ```gcc -E hello.c -o hello.i```
    - ```gcc -Wall -S hello.i -o hello.s```
    - ```as hello.s -o hello.o```
        - ```gcc -c hello.c```
    - ```ld other-command-line-options hello.o -o a.out```
        - or ```gcc hello.o```
- The final executable (a.out) then is ready to be loaded. To run the executable, we type its name at the shell prompt: ```$ ./a.out```
- The shell invokes the loader function, which copies the code and data in the executable file a.out into memory, and then transfers control to the beginning of the program
    - The loader is a program called **execve**, which loads the code and data of the executable object file into memory and then runs the program by jumping to the first instruction
- Linkers and loaders perform various related but conceptually different tasks:
    - *Program Loading*: This refers to copying a program image from hard disk to the main memory in order to put the program in a ready-to-run state. In some cases, program loading also might involve allocating storage space or mapping virtual addresses to disk pages
    - *Relocation*: Compilers and assemblers generate the object code for each input module with a starting address of zero. Relocation is the process of assigning load addresses to different parts of the program by merging all sections of the same type into one section. The code and data section also are adjusted so they point to the correct runtime addresses
    - *Symbol Resolution*: A program is made up of multiple subprograms; reference of one subprogram to another is made through symbols. A linker's job is to resolve the reference by noting the symbol's location and patching the caller's object code
- So a considerable overlap exists between the functions of linkers and loaders. One way to think of them is: the loader does the program loading; the linker does the symbol resolution; and either of them can do the relocation


###Object Files
- Object files comes in three forms:
    - *Relocatable object file*: which contains binary code and data in a form that can be combined with other relocatable object files at compile time to create an executable object file
    - *Executable object file*: which contains binary code and data in a form that can be directly loaded into memory and executed
    - *Shared object file*: which is a special type of relocatable object file that can be loaded into memory and linked dynamically, either at load time or at run time
- Compilers and assemblers generate relocatable object files (also shared object files). Linkers combine these object files together to generate executable object files
- Object files vary from system to system. The first UNIX system used the **a.out** format. Early versions of System V used the **COFF** (common object file format). Windows NT uses a variant of COFF called PE (portable executable) format; IBM uses its own IBM 360 format. Modern UNIX systems, such as Linux and Solaris use the UNIX **ELF** (executable and linking format)


###ELF (relocatable) object file
- The ELF header starts with a 4-byte magic string, \177ELF. The various sections in the ELF relocatable object file are:
    - *.text*, the machine code of the compiled program.
    - *.rodata*, read-only data, such as the format strings in printf statements.
    - *.data*, initialized global variables.
    - *.bss*, uninitialized global variables. BSS stands for block storage start, and this section actually occupies no space in the object file; it is merely a place holder.
    - *.symtab*, a symbol table with information about functions and global variables defined and referenced in the program. This table does not contain any entries for local variables; those are maintained on the stack.
    - *.rel.text*, a list of locations in the .text section that need to be modified when the linker combines this object file with other object files.
    - *.rel.data*, relocation information for global variables referenced but not defined in the current module.
    - *.debug*, a debugging symbol table with entries for local and global variables. This section is present only if the compiler is invoked with a -g option.
    - *.line*, a mapping between line numbers in the original C source program and machine code instructions in the .text section. This information is required by debugger programs.
    - *.strtab*, a string table for the symbol tables in the .symtab and .debug sections.


###Symbols and Symbol Resolution
Every relocatable object file has a symbol table and associated symbols. In the context of a linker, the following kinds of symbols are present:  
- **Global symbols defined by the module and referenced by other modules**. All non-static functions and global variables fall in this category.
- **Global symbols referenced by the input module but defined elsewhere**. All functions and variables with extern declaration fall in this category.
- **Local symbols defined and referenced exclusively by the input module**. All static functions and static variables fall here.

During the process of symbol resolution using static libraries, linker scans the relocatable object files and archives from left to right as input on the command line. During this scan, linker maintains a set of O, relocatable object files that go into the executable; a set U, unresolved symbols; and a set of D, symbols defined in previous input modules. Initially, all three sets are empty.  
- For each input argument on the command line, linker determines if input is an object file or an archive. If input is a relocatable object file, linker adds it to set O, updates U and D and proceeds to next input file.
- If input is an archive, it scans through the list of member modules that constitute the archive to match any unresolved symbols present in U. If some archive member defines any unresolved symbol that archive member is added to the list O, and U and D are updated per symbols found in the archive member. This process is iterated for all member object files.
- After all the input arguments are processed through the above two steps, if U is found to be not empty, linker prints an error report and terminates. Otherwise, it merges and relocates the object files in O to build the output executable file.

NOTE: This also explains why static libraries are placed at the end of the linker command. Special care must be taken in cases of cyclic dependencies between libraries. Input libraries must be ordered so each symbol is referenced by a member of an archive and at least one definition of a symbol is followed by a reference to it on the command line. Also, if an unresolved symbol is defined in more than one static library modules, the definition is picked from the first library found in the command line.

###Relocation
Once the linker has resolved all the symbols, each symbol reference has exactly one definition. At this point, linker starts the process of relocation, which involves the following two steps:  
- Relocating sections and symbol definitions. Linker merges all the sections of the same type into a new single section. For example, linker merges all the .data sections of all the input relocatable object files into a single .data section for the final executable. A similar process is carried out for the .code section. The linker then assigns runtime memory addresses to new aggregate sections, to each section defined by the input module and also to each symbol. After the completion of this step, every instruction and global variable in the program has a unique loadtime address.
- Relocating symbol reference within sections. In this step, linker modifies every symbol reference in the code and data sections so they point to the correct loadtime addresses.

###Loading Shared Libraries from Applications
Shared libraries can be loaded from applications even in the middle of their executions. An application can request a dynamic linker to load and link shared libraries, even without linking those shared libraries to the executable. Linux, Solaris and other systems provides a series of function calls that can be used to dynamically load a shared object. Linux provides system calls, such as **dlopen, dlsym and dlclose**, that can be used to load a shared object, to look up a symbol in that shared object and to close the shared object, respectively. On Windows, LoadLibrary and GetProcAddress functions replace dlopen and dlsym, respectively.

###Tools
- **ar** - create, modify, and extract from archives
    - ```ar -t <staticLibrary.a>```: find the object files packed into this static library
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
- **strings** - list all the printable strings in a binary file
- **strip** - deletes the symbol table information

###Useful reads
####Linker (ld)
- Why does the order in which libraries are linked sometimes cause errors in GCC?
    - http://stackoverflow.com/questions/45135/why-does-the-order-in-which-libraries-are-linked-sometimes-cause-errors-in-gcc
- http://www.linuxjournal.com/article/6463?page=0,0
- http://www.iecc.com/linker/
