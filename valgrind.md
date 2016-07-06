##Valgrind

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

####Sources
- http://es.gnu.org/~aleksander/valgrind/valgrind-memcheck.pdf
