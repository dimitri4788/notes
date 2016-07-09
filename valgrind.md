##Valgrind

Valgrind is an instrumentation framework for building dynamic analysis tools. It comes with a set of tools each of which performs some kind of debugging, profiling, or similar task that helps you improve your programs. Valgrind's architecture is modular, so new tools can be created easily and without disturbing the existing structure.  

A number of useful tools are supplied as standard:  
- *Memcheck* is a memory error detector. It helps you make your programs, particularly those written in C and C++, more correct.
- *Cachegrind* is a cache and branch-prediction profiler. It helps you make your programs run faster.
- *Callgrind* is a call-graph generating cache profiler. It has some overlap with Cachegrind, but also gathers some information that Cachegrind does not.
- *Helgrind* is a thread error detector. It helps you make your multi-threaded programs more correct.
- *DRD* is also a thread error detector. It is similar to Helgrind but uses different analysis techniques and so may find different problems.
- *Massif* is a heap profiler. It helps you make your programs use less memory.
- *DHAT* is a different kind of heap profiler. It helps you understand issues of block lifetimes, block utilisation, and layout inefficiencies.
- *SGcheck* is an experimental tool that can detect overruns of stack and global arrays. Its functionality is complementary to that of Memcheck: SGcheck finds problems that Memcheck can't, and vice versa
- *BBV* is an experimental SimPoint basic block vector generator. It is useful to people doing computer architecture research and development.

Valgrind distinguishes 4 different types of memory leaks in the generated output report:  
- **Still Reachable**
- **Directly Lost**
- **Indirectly Lost**
- **Possibly Lost**
NOTE: Directly and Indirectly Lost leaks are also referred as Definitely Lost leaks.  


####Still reachable blocks
A block of memory is reported to be Still Reachable when Memcheck finds, after process execution ends, at least one pointer with the start address of the block (a start-pointer).

####Definitely Lost blocks
A leak is considered Definitely Lost when, at process exit, there is no pointer or chain of pointers to the leaked memory block:  
- When the start-pointer of a block of memory is fully lost, and also no other interior-pointer to that block of memory is available when process ends; Memcheck will report that block of memory as a ’Directly Lost’ leak.
- When Memcheck finds a valid start-pointer or interior-pointer to a given block of memory, but that pointer is in another block which is ’Directly Lost’, Memcheck will report the block of memory as an ’Indirectly Lost’ leak.
- Finally, when Memcheck finds a valid start-pointer or interior-pointer to a given block of memory, but that pointer is in another block which is ’Indirectly Lost’, Memcheck will report the block of memory as also being ’Indirectly Lost’.
NOTE: The ’Definitely Lost’ memory leaks (both Direct and Indirect) are the ones the programmer should pay more attention to, as they clearly show real programming errors.

####Possibly Lost blocks
The term ’possibly’ here states that Valgrind does not know whether the leak is ’Definitely Lost’ or ’Still Reachable’: but the leaks are really of one of these two types. In other words, it’s a task for the programmer to check whether the leak is reachable or not. The ’Possibly Lost’ leaks will be reported in the absence of a valid start-pointer to the block, but when at least one interior-pointer is found. As you already know, Memcheck cannot decide if the interior-pointer is a valid one, or just a funny coincidence. As a rule of thumb, anyway, those interior-pointers should be treated as valid ones (and decide the real type of leak based on that).


####Command Line
```sh
$ valgrind --tool=memcheck --show-reachable=yes --error-limit=no --leak-check=full --suppressions=<file.supp> someprog

# Use this to send the output of valgrind to a file
$ valgrind --tool=memcheck --show-reachable=yes --error-limit=no --leak-check=full --suppressions=<file.supp> someprog 2>&1 | tee -a ~/fileName.txt
```

####Flags
- --tool=<toolname> [default: memcheck]  
Run the Valgrind tool called toolname, e.g. memcheck, cachegrind, callgrind, helgrind, drd, massif, lackey, none, exp-sgcheck, exp-bbv, exp-dhat, etc.

- --show-reachable=<yes|no>, --show-possibly-lost=<yes|no>  
These options provide an alternative way to specify the leak kinds to show:  
--show-reachable=no --show-possibly-lost=yes is equivalent to --show-leak-kinds=definite,possible.  
--show-reachable=no --show-possibly-lost=no is equivalent to --show-leak-kinds=definite.  
--show-reachable=yes is equivalent to --show-leak-kinds=all.

- --error-limit=<yes|no> [default: yes]  
When enabled, Valgrind stops reporting errors after 10,000,000 in total, or 1,000 different ones, have been seen. This is to stop the error tracking machinery from becoming a huge performance overhead in programs with many errors.

- --leak-check=<no|summary|yes|full> [default: summary]  
When enabled, search for memory leaks when the client program finishes. If set to summary, it says how many leaks occurred. If set to full or yes, each individual leak will be shown in detail and/or counted as an error, as specified by the options --show-leak-kinds and --errors-for-leak-kinds.

- --suppressions=<filename> [default: $PREFIX/lib/valgrind/default.supp]  
Specifies an extra file from which to read descriptions of errors to suppress. You may use up to 100 extra suppression files.

- --show-leak-kinds=<set> [default: definite,possible]  
Specifies the leak kinds to show in a full leak search, in one of the following ways:  
    - a comma separated list of one or more of definite indirect possible reachable
    - all to specify the complete set (all leak kinds). It is equivalent to --show-leak-kinds=definite,indirect,possible,reachable
    - none for the empty set

####Configiration file for Valgrind
A file in the home directory with name **.valgrindrc** can be created with content for example:  
```sh
--memcheck:leak-check=full
--show-leak-kinds=all
--show-reachable=yes
--suppressions=../valgrind.suppressions
--suppressions=/home/deep/devel/wxGTK-2.8.12.supp
```
Rather than having to type all the command line options on the terminal each time, it's more sensible to write it to an rc file. Each time it runs, valgrind looks for options in files called ~/.valgrindrc and ./.valgrindrc.

####Valgrind Suppression File
Valgrind is (mostly) a memory error detector for Linux. It's very good at finding leaks and uninitialised variables; unfortunately it's too good, and usually produces a number of false positives. It comes with suppression files which automatically silence some of these.  
When valgrind runs its default tool, Memcheck, it automatically tries to read a file called $PREFIX/lib/valgrind/default.supp ($PREFIX will normally be /usr). However you can make it use additional suppression files of your choice by adding --suppressions=<filename> to your command-line invocation. You can repeat this up to 100 times, which should be sufficient for most situations ;)


####Sources
- http://es.gnu.org/~aleksander/valgrind/valgrind-memcheck.pdf
- http://valgrind.org/docs/manual/mc-manual.html
- https://wiki.wxwidgets.org/Valgrind_Suppression_File_Howto
