## C++11 and C++14 stuff

### C++11
- auto
```cpp
// C++98
map<int,string>::iterator i = m.begin();
double const xlimit = config["xlimit"];
singleton& s = singleton::instance();
 
// C++11
auto i = begin(m);
auto const xlimit = config["xlimit"];
auto& s = singleton::instance();

auto i = 42;        // i is an int
auto l = 42LL;      // l is an long long
auto p = new foo(); // p is a foo*
```
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
```cpp
class B 
{
    public:
       virtual void f(int) {std::cout << "B::f" << std::endl;}
};

class D : public B
{
    public:
       virtual void f(int) override final {std::cout << "D::f" << std::endl;}
};

class F : public D
{
    public:
       virtual void f(int) override {std::cout << "F::f" << std::endl;}
};
```
- Strongly typed enums
```cpp
enum class Options {None, One, All};
Options o = Options::All;
```
- Lambdas
- Non member begin() and end()
```cpp
vector<int> v;
int a[100];
 
// C++98
sort( v.begin(), v.end() );
sort( &a[0], &a[0] + sizeof(a)/sizeof(a[0]) );
 
// C++11
sort( begin(v), end(v) );
sort( begin(a), end(a) );
```
- static_assert and type traits
    - assertion check at compile time
```cpp
template <typename T1, typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1 + t2)
{
    static_assert(std::is_integral<T1>::value, "Type T1 must be integral");
    static_assert(std::is_integral<T2>::value, "Type T2 must be integral");

    return t1 + t2;
}
```
- Uniform Initialization Syntax
```cpp
// C++98
vector<int>     v;
for( int i = 1; i <= 4; ++i ) v.push_back(i);
 
// C++11
vector<int>     v   { 1, 2, 3, 4 };
```
- Deleted and Defaulted Functions
- Threading Library
- std::array for static length arrays
- std::tuple
```cpp
typedef std::tuple <int, double, long &, const char *> test_tuple;
long lengthy = 12;
test_tuple proof (18, 6.5, lengthy, "Ciao!");
 
lengthy = std::get<0>(proof);  // Assign to 'lengthy' the value 18.
std::get<3>(proof) = " Beautiful!";  // Modify the tuple’s fourth element.
```
- constexpr
    - A constant expression has never been allowed to contain a function call or object constructor.
    - A C++03 compiler has no way of knowing if get_five() actually is constant at runtime.
    - In theory, this function could affect a global variable, call other non-runtime constant functions, etc.
    - C++11 introduced the keyword constexpr, which allows the user to guarantee that a function or object constructor is a compile-time constant.
    - This allows the compiler to understand, and verify, that get_five() is a compile-time constant.
    - The above example can be rewritten as follows:
```cpp
int get_five() {return 5;}
int some_value[get_five() + 7]; // Create an array of 12 integers. Ill-formed C++

constexpr int get_five() {return 5;}
int some_value[get_five() + 7]; // Create an array of 12 integers. Legal C++11
```







### C++14
- auto
    - Return type deduction for functions
```cpp
auto getvalue()
{
    return 2; //Compiler will deduce what type it is returning
}
```
- constexpr
- The [[deprecated]] Attribute
    - The attribute-token deprecated can be used to mark names and entities whose use is still allowed, but is discouraged for some reason.
    - For example, the following function foo is deprecated:
```cpp
[[deprecated]]
void foo(int);

[[deprecated]] int f();
[[deprecated("g() is thread-unsafe. Use h() instead")]]
void g( int& x );
void h( int& x );
void test() 
{
    int a = f(); // warning: 'f' is deprecated
    g(a); // warning: 'g' is deprecated: g() is thread-unsafe. Use h() instead
}
```
- Digit separators
```cpp
auto integer_literal = 1'000'000;
auto floating_point_literal = 0.000'015'3;
auto binary_literal = 0b0100'1100'0110;
auto silly_example = 1'0'0'000'00;
```








### Sources
- http://www.codeproject.com/Articles/570638/Ten-Cplusplus-Features-Every-Cplusplus-Developer#lambdas
- http://blog.smartbear.com/c-plus-plus/the-biggest-changes-in-c11-and-why-you-should-care/
- http://en.wikipedia.org/wiki/C%2B%2B11#Tuple_types
- http://en.wikipedia.org/wiki/C%2B%2B14
