##Valgrind

```sh
$ valgrind --tool=memcheck --show-reachable=yes --error-limit=no --leak-check=full --suppressions=<file.supp> someprog

# Use this to send the output of valgrind to a file
$ valgrind --tool=memcheck --show-reachable=yes --error-limit=no --leak-check=full --suppressions=<file.supp> someprog 2>&1 | tee -a ~/serverMemLeak.txt
```

####Flags
- --tool=<toolname> [default: memcheck]  
Run the Valgrind tool called toolname, e.g. memcheck, cachegrind, callgrind, helgrind, drd, massif, lackey, none, exp-sgcheck, exp-bbv, exp-dhat, etc.

- --suppressions=<filename> [default: $PREFIX/lib/valgrind/default.supp]  
Specifies an extra file from which to read descriptions of errors to suppress. You may use up to 100 extra suppression files.







####Sources
- http://es.gnu.org/~aleksander/valgrind/valgrind-memcheck.pdf
-
