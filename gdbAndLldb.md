####GDB and LLDB Tutorial






Debugging a core file:
- Make sure your system will generate core files
```sh
#As core files can be huge, may systems disable the generation of core
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
