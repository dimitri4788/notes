## Makefile tutorial


```
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files

# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
INCLUDES = -I/home/newhall/include  -I../include

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = -L/home/newhall/lib  -L../lib









```

### Source
- http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
