Useful info and best practices for writing Python code
======================================================

Useful Information
------------------
- The *import modu* statement will look for the file modu.py in the same directory as the caller if it exists.
    - If it is not found, the Python interpreter will search for modu.py in the "path" recursively and raise an ImportError exception if it is not found.
    - Once modu.py is found, the Python interpreter will execute the module in an isolated scope.
    - Any top-level statement in modu.py will be executed, including other imports if any. Function and class definitions are stored in the module's dictionary.



Good/Bad practices
------------------
- `from modu import *`: This is generally considered bad practice. 



