## Test Doubles (for unit testing)

###Test Double
In automated unit-testing, if the software consists of a complex set of objects or procedures interacting together to create the final result, it may be necessary to use objects or procedures that look and behave like their release-intended counterparts, but are actually simplified versions that reduce the complexity and facilitate testing. A test double is a generic term used for these objects or procedures.

- Types of test doubles
    - Stub
    - Mock object
    - Fake object
    - Dummy objects


**Stub**
- A routine that doesn't actually do anything other than declare itself and the parameters it accepts. Stubs are used commonly as placeholders for routines that still need to be developed. The stub contains just enough code to allow it to be compiled and linked with the rest of the program.
- A stub in software development is a piece of code used to stand in for some other programming functionality. A stub may simulate the behavior of existing code (such as a procedure on a remote machine) or be a temporary substitute for yet-to-be-developed code.
- A stub is a routine that doesn't actually do anything other than declaring itself and the parameters it accepts and returning something that is usually the values expected in one of the "happy scenarios" for the caller.
- Stubs are therefore most useful in porting, distributed computing as well as general software development and testing.

**Mock Object**
- In object-oriented programming, mock objects are simulated objects that mimic the behavior of real objects. A programmer typically creates a mock object to test the behavior of some other object, in much the same way that a car designer uses a crash test dummy to simulate the dynamic behavior of a human in vehicle impacts.
- In a unit test, mock objects can simulate the behavior of complex, real objects and are therefore useful when a real object is impractical or impossible to incorporate into a unit test.
- If an actual object has any of the following characteristics, it may be useful to use a mock object in its place:
    - the object supplies non-deterministic results (e.g., the current time or the current temperature);
    - it has states that are difficult to create or reproduce (e.g., a network error);
    - it is slow (e.g., a complete database, which would have to be initialized before the test);
    - it does not yet exist or may change behavior;
    - it would have to include information and methods exclusively for testing purposes (and not for its actual task).

**Fake object**
- Fakes are the simpler of the two (Fake and Mock objects), simply implementing the same interface as the object that they represent and returning pre-arranged responses. Thus a fake object merely provides a set of method stubs
- Used as a simpler implementation, e.g. using an in-memory database in the tests instead of doing real database access

**Dummy objects**
- They are passed around but never actually used. Usually they are just used to fill parameter lists.


### Sources
- http://martinfowler.com/articles/mocksArentStubs.html
- https://en.wikipedia.org/wiki/Test_double
- http://www.webopedia.com/TERM/S/stub.html
- https://code.google.com/p/googlemock/wiki/ForDummies
