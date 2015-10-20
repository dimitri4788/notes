C++11 and C++14 stuff
=====================

C++11
-----
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
```cpp
class X
{
    public:
        X();
        X(const X&) = default;              //use compile-generated default constructor
        X& operator=(const X &) = delete;   //tells compiler not to use this constructor
};
```
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
- Regular expressions
    - Header name "regex"
    - http://www.informit.com/articles/article.aspx?p=2079020
- Threading facilities
    - std::thread
    - std::mutex
    - std::condition_variable
- Smart pointers
    - std::unique_ptr
    - std::shared_ptr
    - std::weak_ptr
- Right angle bracket
    - C++03's parser defines ">>" as the right shift operator or stream extraction operator in all cases.
    - However, with nested template declarations, there is a tendency for the programmer to neglect to place a space between the two right angle brackets, thus causing a compiler syntax error.
    - C++11 improves the specification of the parser so that multiple right angle brackets will be interpreted as closing the template argument list where it is reasonable.
```cpp
template<bool Test> class SomeType;
std::vector<SomeType<1>2>> x1;  // Interpreted as a std::vector of SomeType<true>,
                                // followed by "2 >> x1", which is not legal syntax for a declarator. 1 is true.
std::vector<SomeType<(1>2)>> x1;  // Interpreted as std::vector of SomeType<false>,
                                  // followed by the declarator "x1", which is legal C++11 syntax. (1>2) is false.
```
- New Types
    - long long, unsigned long long: to support 64-bit integers
    - char16_t, char32_t: to support 16-bit and 32-bit character representations
- Member In-Class Initialization
```cpp
class Session
{
        int a = 10;     // In-Class Initialization
        double b {2.5}; // In-Class Initialization
    public:
        Session(){}
        Session(double d) : b(d) {}
        Session(int x, double y) : a(x), b(d) {}
};
```
- New STL Containers
    - unordered_map
    - unordered_multimap
    - unordered_set
    - unordered_multiset
- Inheriting Constructors
```cpp
class Base
{
    public:
        Base() : q(0), w(0) {}
        Base(int k) : q(k), w(100) {}
        Base(double x) : q(-1), w(x) {}
        Base(int k, double x) : q(k), w(x) {}

    private:
        int q;
        double w;
};

class Derived
{
    public:
        using Base::Base;
        Derived() : j(-100) {}
        Derived(double x) : Base(2*x), j(int(x)) {}
        Derived(int i) : j(int(x)), Base(i, 0.5*i) {}

    private:
        short j;
};

int main()
{
    Derived o1;             //use Derived()
    Derived o2(18.81);      //use Derived(double) instead of Base(double)
    Derived o3(10, 1.8);    //use Base(int, double)

}
```


















C++14
-----
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
- Tuple addressing via type
    - The std::tuple type introduced in C++11 allows an aggregate of typed values to be indexed by a compile-time constant integer.
    - C++14 extended this to allow fetching from a tuple by type instead of by index.
```cpp
tuple<string, string, int> t("foo", "bar", 7);
int i = get<int>(t);        // i == 7
int j = get<2>(t);          // Same as before: j == 7
string s = get<string>(t);  // Compile-time error due to ambiguity
```










Sources
-------
- http://www.codeproject.com/Articles/570638/Ten-Cplusplus-Features-Every-Cplusplus-Developer#lambdas
- http://blog.smartbear.com/c-plus-plus/the-biggest-changes-in-c11-and-why-you-should-care/
- http://en.wikipedia.org/wiki/C%2B%2B11#Tuple_types
- http://en.wikipedia.org/wiki/C%2B%2B14
