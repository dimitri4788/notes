GDB and LLDB Tutorial
=====================

NOTE: You can use gdb to debug programs written in C and C++. For more information, see supported languages: https://sourceware.org/gdb/current/onlinedocs/gdb/Supported-Languages.html#Supported-Languages

<br>

GDB
---
Shell Commands | Explanation
--- | ---
`$ gdb` | Start GDB
`$ gdb program` | Start GDB with executable program
`$ gdb program coreFile` | Start with both an executable program and a core file
`$ gdb program 1234` | You can, instead, specify a process ID as a second argument, if you want to debug a running process
`$ gdb -help` | To display all available options and briefly describe their use (‘gdb -h’ is a shorter equivalent).


GDB Session Commands | Explanation
--- | ---
`(gdb) q + ENTER` | To quit GDB
`(gdb) quit + ENTER` | To quit GDB
`(gdb) An interrupt (often Ctrl-c) ` | Does not exit from gdb, but rather terminates the action of any gdb command that is in progress and returns to gdb command level.

LLDB
----
- http://lldb.llvm.org/lldb-gdb.html

<br>
<br>

Debugging a core file
---------------------
- Make sure your system will generate core files
```sh
#As core files can be huge, many systems disable the generation of core
#   files by default and you may need to turn them on. First take a look at your current settings:
$ ulimit -a

core file size        (blocks, -c) 0
data seg size         (kbytes, -d) unlimited
file size             (blocks, -f) unlimited
max locked memory     (kbytes, -l) 32
max memory size       (kbytes, -m) unlimited
open files                    (-n) 1024
pipe size          (512 bytes, -p) 8
stack size            (kbytes, -s) 8192
cpu time             (seconds, -t) unlimited
max user processes            (-u) 960
virtual memory        (kbytes, -v) unlimited

#The above report shows that the core file size is set to 0, which means that core
#   files will not be generated. You need to change this setting to "unlimited" as follows:
$ ulimit -c unlimited
```


Sources
-------
- https://sourceware.org/gdb/current/onlinedocs/gdb/
- http://lldb.llvm.org/lldb-gdb.html
- http://processors.wiki.ti.com/index.php/Multithreaded_Debugging_Made_Easier_by_Forcing_Core_Dumps
- http://lldb.llvm.org/tutorial.html
- Building GDB for Darwin: https://sourceware.org/gdb/wiki/BuildingOnDarwin
