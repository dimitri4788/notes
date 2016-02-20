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
)   move forward one sentence
}   move forward one paragraph


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
Ctrl-E  scroll up one line
Ctrl-Y  scroll down one line

n   next matching search pattern
N   previous matching search pattern
*   next whole word under cursor
#   previous whole word under cursor
g*  next matching search (not whole word) pattern under cursor
g#  previous matching search (not whole word) pattern under cursor

%   jump to matching bracket { } [ ] ( )
```

Vim as Language
---------------
Arguably the most brilliant thing about vim is that as you use it you begin to think in it. vim is set up to function like a language, complete with nouns, verbs, and adverbs.  
**Verbs**  
Verbs are the actions we take, and they can be performed on nouns. Here are some examples:  
```
d:      delete
c:      change
y:      yank (copy)
v:      visually select (V for line vs. character)
```

**Modifiers**  
Modifiers are used before nouns to describe the way in which you’re going to do something. Some examples:  
```
i:      inside
a:      around
NUM:    number (e.g.: 1, 2, 10)
t:      searches for something and stops before it
f:      searches for that thing and lands on it
/:      find a string (literal or regex)
```

**Nouns**  
In English, nouns are objects you do something to. They are objects. With vim it’s the same. Here are some vim nouns:  
```
w:      word
s:      sentence
):      sentence (another way of doing it)
p:      paragraph
}:      paragraph (another way of doing it)
t:      tag (think HTML/XML)
b:      block (think programming)
```

Cool stuff
----------
```
d2w         delete two words
diw         delete the word the cursor is on
caw         delete the word the cursor is on and put in insert mode
di)         delete everything inside the bracket ( and )
di}         delete everything inside the bracket { and }
da)         delete everything inside the bracket and including ( and )
yi)         yank all text inside ( and )
va”         visually select inside and including double quotes
va’         visually select everything inside and including single quotes
vi}         visually select everything inside single quotes
viw         visually select the word the cursor is on
cis         change inside sentence (delete the current one and enter insert mode)
yip         yank inside paragraph (copy the paragraph you're in)
ct)         change to close bracket (change the text from where you are to the next close bracket ')')
ct{         change to open bracket (change the text from where you are to the next open bracket '{')
dt          delete to the next period
yt;         copy to the next semicolon
vt,         visually select to the next comma
Shift+D     deletes from the cursor until the end of line
ZZ          a faster way to do :wq
```

A search reference
------------------
```
/{string}: search for string
t:         jump up to a character
f:         jump onto a character
*:         search for other instances of the word under your cursor
n:         go to the next instance when you’ve searched for a string
N:         go to the previous instance when you’ve searched for a string
;:         go to the next instance when you’ve jumped to a character
,:         go to the previous instance when you’ve jumped to a character
Example:
f<          jump forward and land on the < character
t)          jump forward and land right before ')'
```

Basic change/insert options
---------------------------
```
i: insert before the cursor
a: append after the cursor
I: insert at the beginning of the line
A: append at the end of the line
o: open a new line below the current one
O: open a new line above the current one
r: replace the one character under your cursor
R: replace the character under your cursor, but just keep typing afterwards
cm: change whatever you define as a movement, e.g. a word, or a sentence, or a paragraph.
C: change the current line from where you’re at
ct?: change change up to the question mark
s: substitute from where you are to the next command (noun)
S: substitute the entire current line
```

Deleting text
-------------
```
x: exterminate (delete) the character under the cursor
X: exterminate (delete) the character before the cursor
dm: delete whatever you define as a movement, e.g. a word, or a sentence, or a paragraph.
dd: delete the current line
dt.: delete delete from where you are to the period
D: delete to the end of the line
J: join the current line with the next one (delete what’s between)
```

Undo and Redo
-------------
```
u: undo your last action.
Ctrl-r: redo the last action
```

A text object reference
-----------------------
```
words:          iw and aw
sentences:      is and as
paragraphs:     ip and ap
single quotes:  i' and a'
double quotes:  i" and a"
back ticks:     i` and a`
parenthesis:    i( and a(
brackets:       i[ and a[
braces:         i{ and a{
tags:           it and at
```

How to insert text at beginning of each line in Vim?
----------------------------------------------------
Use Ctrl+V to enter visual block mode  
Move Up/Downto select the columns of text in the lines you want to comment  
Then hit Shift+i and type the text you want to insert  
Then hit Esc, wait 1 second and the inserted text will appear on every line  

How to add text at the end of each line in Vim?
-----------------------------------------------
(comma in this example)  
:%s/$/,/

