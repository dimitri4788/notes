## C++11 and C++14 stuff

### C++11
- auto
- nullptr
    - never use the literal 0 or the macro NULL which are ambiguous because they could be either an integer or a pointer
```cpp
void f(int); //#1
void f(char *);//#2
//C++03
f(0); //which f is called?
//C++11
f(nullptr) //unambiguous, calls #2
```
- Range based for loops
```cpp
// C++98
for( vector<int>::iterator i = v.begin(); i != v.end(); ++i ) 
{
    total += *i;
}
 
// C++11
for( auto d : v )
{
    total += d;
}
```
- Override and final
- Strongly typed enums
- Lambdas
- non member begin() and end()
- static_assert and type traits
    - assertion check at compile-time
- Uniform Initialization Syntax
- Deleted and Defaulted Functions
- Threading Library
- std::array for static-length arrays



### C++14
- auto
    - Return type deduction for functions
- constexpr







### Sources
- http://www.codeproject.com/Articles/570638/Ten-Cplusplus-Features-Every-Cplusplus-Developer#lambdas
- http://blog.smartbear.com/c-plus-plus/the-biggest-changes-in-c11-and-why-you-should-care/
