###Valgrind

```sh
$ valgrind --tool=memcheck --show-reachable=yes --error-limit=no --leak-check=full --suppressions=<file.supp> someprog

#Use this to send the output of valgrind to a file
$ valgrind --tool=memcheck --show-reachable=yes --error-limit=no --leak-check=full --suppressions=<file.supp> someprog 2>&1 | tee -a ~/serverMemLeak.txt
```







####Sources
-
-
