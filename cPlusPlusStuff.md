## C/C++ stuff

### C++
**Forward Declaration:**
- When you forward declare a type, all the compiler knows is that this type exists; it knows nothing about its size, members, or methods. This is why it's called an incomplete type. Therefore, you cannot use the type to declare a member, or a base class, since the compiler would need to know the layout of the type.

**Move semantics and rvalue references in C++11:**
- http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html

**A Base Class pointer can point to a derived class object. Why is the vice-versa not true?**
- http://stackoverflow.com/questions/4937180/a-base-class-pointer-can-point-to-a-derived-class-object-why-is-the-vice-versa
- http://stackoverflow.com/questions/9752255/why-cant-a-derived-class-pointer-point-to-a-base-class-object-without-casting

**Smart Pointers**
- http://herbsutter.com/2013/05/29/gotw-89-solution-smart-pointers/

**Temporary Objects**
- http://herbsutter.com/2013/05/13/gotw-2-solution-temporary-objects/




### Sources
- http://stackoverflow.com/questions/553682/when-can-i-use-a-forward-declaration
- http://stackoverflow.com/questions/4757565/c-forward-declaration
