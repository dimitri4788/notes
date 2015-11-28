Best practices for writing Python code
======================================

Good/Bad practices
------------------
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
```
- 











Useful Information
------------------
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









Source
------
- http://docs.python-guide.org/en/latest/
- http://learnpythonthehardway.org/book/index.html
