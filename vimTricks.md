Some cool tricks in Vim
=======================

This file contains some useful tricks in Vim.

<br>

####Make vim into a hex editor
:%!xxd  
:%!xxd -r  

####Replace all occurrences in all lines of word foo with bar
:%s/foo/bar/g

####Replace all occurrences in current line of word foo with bar
:s/foo/bar/g

####Creates an HTML rendering of the current file:
:%TOhtml

####Show trailing whitespaces:
/\s\+$

####In normal mode, typing gg=G will reindent the entire file
gg=G

####Search for FRED OR JOE (a '\' is needed before '|')
/fred\|joe

####Search for exactly 4 digit numbers
/\<\d\d\d\d\>  
/\<\d\{4}\>  

####find 3 empty lines
/^\n\{3}

####Search for goat between lines 20 and 30
/\%>20l\%<30lgoat

####Delete DOS returns ^M
:%s/\r//g

####Press 'R' (uppercase)
Use R to enter insert mode with an overstrike cursor, which types over existing characters

####Jump top/middle/bottom of the screen using
H/M/L

####Toggle the case of the character under the cursor
~

####Clears the current line and enters insert mode
S

####Highlight non-ASCII characters
/[^\x00-\x7F]  
This will do a negative match (via [^]) for characters between ASCII 0x00 and ASCII 0x7F (0-127), and appears to work in simple test. For extended ASCII, extend the range up to \xFF instead of \x7F using /[^\x00-\xFF].

####All the right moves
```
h   move one character left
j   move one row down
k   move one row up
l   move one character right
w   move to beginning of next word
b   move to previous beginning of word
e   move to end of word
W   move to beginning of next word after a whitespace
B   move to beginning of previous word before a whitespace
E   move to end of word before a whitespace


0   move to beginning of line
$   move to end of line
gg  move to first line
G   move to last line
nG  move to n'th line of file (where n is a number)

H   move to top of screen
M   move to middle of screen
L   move to bottom of screen

z.  put the line with the cursor at the center
zt  put the line with the cursor at the top
zb  put the line with the cursor at the bottom of the screen

Ctrl-D  move half-page down
Ctrl-U  move half-page up
Ctrl-B  page up
Ctrl-F  page down
Ctrl-o  jump to last cursor position
Ctrl-i  jump to next cursor position

n   next matching search pattern
N   previous matching search pattern
*   next whole word under cursor
#   previous whole word under cursor
g*  next matching search (not whole word) pattern under cursor
g#  previous matching search (not whole word) pattern under cursor

%   jump to matching bracket { } [ ] ( )
```

####Cool stuff
```
diw         delete the word the cursor is on
caw         delete the word the cursor is on and put in insert mode
di)         delete everything inside the bracket ( and )
di}         delete everything inside the bracket { and }
da)         dadelete everything inside the bracket and including ( and )
yi)         yank all text inside ( and )
va”         visually select inside and including double quotes
va’         visually select everything inside and including single quotes
vi}         visually select everything inside single quotes
viw         visually select the word the cursor is on
Shift+D     deletes from the cursor until the end of line
```
