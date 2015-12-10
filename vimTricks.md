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

####Search for FRED OR JOE
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
