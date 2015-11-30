Best practices for writing Python code
======================================

Best practices
--------------
- `from modu import *`: This is generally considered bad practice.
    - Using `from modu import func` is a way to pinpoint the function you want to import and put it in the global namespace.
    - Very bad: `from modu import *`
        - `x = sqrt(4)` #Is sqrt part of modu? A builtin? Defined above?
    - Better: `from modu import sqrt`
        - `x = sqrt(4)` #sqrt may be part of modu, if not redefined in between
    - Best: `import modu`
        - `x = modu.sqrt(4)` #sqrt is visibly part of modu's namespace
- Any directory with an __init__.py file is considered a Python package.
    - Different modules in the package are imported in a similar manner as plain modules, but with a special behavior for the __init__.py file, which is used to gather all package-wide definitions.
    - A file modu.py in the directory pack/ is imported with the statement `import pack.modu`. This statement will look for an __init__.py file in pack, execute all of its top-level statements. Then it will look for a file named pack/modu.py and execute all of its top-level statements. After these operations, any variable, function, or class defined in modu.py is available in the pack.modu namespace.
    - Leaving an __init__.py file empty is considered normal and even a good practice, if the package’s modules and sub-packages do not need to share any code.
    - Importing deeply nested packages: import very.deep.module as mod. This allows you to use mod in place of the verbose repetition of very.deep.module.
- One peculiarity of Python that can surprise beginners is that strings are immutable. This means that when constructing a string from its parts, it is much more efficient to accumulate the parts in a list, which is mutable, and then glue ('join') the parts together when the full string is needed. One thing to notice, however, is that list comprehensions are better and faster than constructing a list in a loop with calls to append().
```python
#Bad
# create a concatenated string from 0 to 19 (e.g. "012..1819")
nums = ""
for n in range(20):
nums += str(n)   # slow and inefficient
print nums

#Good
# create a concatenated string from 0 to 19 (e.g. "012..1819")
nums = []
for n in range(20):
nums.append(str(n))
print "".join(nums)  # much more efficient

#Best
# create a concatenated string from 0 to 19 (e.g. "012..1819")
nums = [str(n) for n in range(20)]
print "".join(nums)

#You can also use the % formatting operator to concatenate a pre-determined number of strings besides str.join() and +.
foo = 'foo'
bar = 'bar'
foobar = '%s%s' % (foo, bar) # It is OK
foobar = '{0}{1}'.format(foo, bar) # It is better
foobar = '{foo}{bar}'.format(foo=foo, bar=bar) # It is best

#Using join() is not always best. In the instances where you are creating a new string from a pre-determined number of strings, using the addition operator is actually faster, but in cases like above or in cases where you are adding to an existing string, using join() should be your preferred method.
foo = 'foo'
bar = 'bar'
foobar = foo + bar  # This is good
foo += 'ooo'  # This is bad, instead you should do:
foo = ''.join([foo, 'ooo'])
```
- Explicit code
```python
#Bad
def make_complex(*args):
    x, y = args
    return dict(**locals())

#Good
def make_complex(x, y):
    return {'x': x, 'y': y}
```
- PEP 8
    - PEP 8 is the de-facto code style guide for Python.
    - `pip install pep8`
    - `pep8 fileName.py`
- autopep8
    - The program autopep8 can be used to automatically reformat code (in-place) in the PEP 8 style. Install the program with
        - `pip install autopep8`
        - `autopep8 --in-place fileName.py`
    - Excluding the `--in-place` flag will cause the program to output the modified code directly to the console for review
    - The `--aggressive` flag will perform more substantial changes and can be applied multiple times for greater effect
- Check if variable equals a constant
    - You don’t need to explicitly compare a value to True, or None, or 0 - you can just add it to the if statement. See Truth Value Testing for a list of what is considered false.
    - Truth Value Testing
        - The following values are considered false: None, False, 0, 0L, 0.0, 0j, '', (), [], {}, instances of user-defined classes if the class defines a __nonzero__() or __len__() method, when that method returns the integer zero or bool value False
        - All other values are considered true — so objects of many types are always true
    ```python
    #Bad
    if attr == True:
        print 'True!'

    if attr == None:
        print 'attr is None!'

    #Good
    # Just check the value
    if attr:
        print 'attr is truthy!'

    # or check for the opposite
    if not attr:
        print 'attr is falsey!'

    # or, since None is considered false, explicitly check for it
    if attr is None:
        print 'attr is None!'
    ```
- Access a Dictionary Element
    - Don’t use the dict.has_key() method. Instead, use x in d syntax, or pass a default argument to dict.get().
    ```python
    #Bad
    d = {'hello': 'world'}
    if d.has_key('hello'):
        print d['hello']    # prints 'world'
    else:
        print 'default_value'

    #Good
    d = {'hello': 'world'}

    print d.get('hello', 'default_value') # prints 'world'
    print d.get('thingy', 'default_value') # prints 'default_value'

    # Or:
    if 'hello' in d:
        print d['hello']
    ```
- Short Ways to Manipulate Lists
```python
#Bad
# Filter elements greater than 4
a = [3, 4, 5]
b = []
for i in a:
if i > 4:
b.append(i)

#Good
a = [3, 4, 5]
b = [i for i in a if i > 4]
# Or:
b = filter(lambda x: x > 4, a)

#Bad
# Add three to all list members.
a = [3, 4, 5]
for i in range(len(a)):
a[i] += 3

#Good
a = [3, 4, 5]
a = [i + 3 for i in a]
# Or
a = map(lambda i: i + 3, a)

#Use enumerate() keep a count of your place in the list
a = [3, 4, 5]
for i, item in enumerate(a):
    print i, item
```
- Read from a file
    - Use the with open syntax to read from files. This will automatically close files for you.
    ```python
    #Bad
    f = open('file.txt')
    a = f.read()
    print a
    f.close()

    #Good
    with open('file.txt') as f:
    for line in f:
    print line
    ```
    - The with statement is better because it will ensure you always close the file, even if an exception is raised inside the with block.
- Line Continuations
```python
#Bad
my_very_big_string = """For a long time I used to go to bed early. Sometimes, \
    when I had put out my candle, my eyes would close so quickly that I had not even \
    time to say “I’m going to sleep.”"""

from some.deep.module.inside.a.module import a_nice_function, another_nice_function, yet_another_nice_function

#Good
my_very_big_string = (
    "For a long time I used to go to bed early. Sometimes, "
    "when I had put out my candle, my eyes would close so quickly "
    "that I had not even time to say “I’m going to sleep.”"
)

from some.deep.module.inside.a.module import (a_nice_function, another_nice_function, yet_another_nice_function)
```
- Installation instructions are often reduced to one command: `pip install <module>` or `python setup.py install`
- Documenting Code (Comments)
    - Do not use triple-quote strings to comment code
        - This is not a good practice, because line-oriented command-line tools such as grep will not be aware that the commented code is inactive.
        - It is better to add hashes at the proper indentation level for every commented line.
    - Block Comments
        - Block comments generally apply to some (or all) code that follows them, and are indented to the same level as that code.
        - Each line of a block comment starts with a # and a single space (unless it is indented text inside the comment).
        - Paragraphs inside a block comment are separated by a line containing a single # .
    - Inline Comments
        - An inline comment is a comment on the same line as a statement.
        - Inline comments should be separated by at least two spaces from the statement. They should start with a # and a single space.






<br>

Useful Stuff
------------
- The `import modu` statement will look for the file modu.py in the same directory as the caller if it exists.
    - If it is not found, the Python interpreter will search for modu.py in the "path" recursively and raise an ImportError exception if it is not found.
    - Once modu.py is found, the Python interpreter will execute the module in an isolated scope.
    - Any top-level statement in modu.py will be executed, including other imports if any. Function and class definitions are stored in the module's dictionary.
- Why Python is Slow: Looking Under the Hood: https://jakevdp.github.io/blog/2014/05/09/why-python-is-slow/
- Mutable and immutable types
    - Python has two kinds of built-in or user-defined types: *Mutable* and *Immutable*
        - Mutable types are those that allow in-place modification of the content. Typical mutables are lists and dictionaries: All lists have mutating methods, like list.append() or list.pop(), and can be modified in place. The same goes for dictionaries.
        - Immutable types provide no method for changing their content. For instance, the variable x set to the integer 6 has no "increment" method. If you want to compute x + 1, you have to create another integer and give it a name.
        ```python
        my_list = [1, 2, 3]
        my_list[0] = 4
        print my_list  # [4, 2, 3] <- The same list as changed

        x = 6
        x = x + 1  # The new x is another object
        ```
- Create an ignored variable
    - If you need to assign something (for instance, in Unpacking) but will not need that variable, use __
    ```python
    filename = 'foobar.txt'
    basename, __, ext = filename.rpartition('.')
    ```
- Create a length-N list of the same thing: `four_nones = [None] * 4`
- Create a length-N list of lists: `four_lists = [[] for __ in xrange(4)]`
- Create a string from a list
```python
letters = ['s', 'p', 'a', 'm']
word = ''.join(letters)
```

<br>

Source
------
- http://docs.python-guide.org/en/latest/
- http://learnpythonthehardway.org/book/index.html
