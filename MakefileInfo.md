## Makefile tutorial


```
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files

# Define the C compiler to use
CC = gcc

# Define any compile-time flags
CFLAGS = -Wall -g

# Define any directories containing header files other than /usr/include
INCLUDES = -I/home/newhall/include  -I../include

# Define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = -L/home/newhall/lib  -L../lib

# Define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lmylib -lm


# Define the C source files
SRCS = emitter.c error.c init.c lexer.c main.c symbol.c parser.c

# Define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

# Define the executable file 
MAIN = mycc

all:    $(MAIN)
        @echo  Simple compiler named mycc has been compiled

$(MAIN): $(OBJS) 
        $(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# This is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
.c.o:
        $(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
        $(RM) *.o *~ $(MAIN)




```

### Source
- http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
