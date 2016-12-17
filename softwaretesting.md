Software Testing
================

```
               |----------|                     |--------|
               | Software |                     | Output | --> Yes (Done)
Test Input --> | under    | --> Test Output --> | okay?  |
               | test     |                     |        | --> No --> Debug
               |----------|                     |--------|
```
**developer**: "*I want this code to succeed*"  
**tester**: "*I want this code to fail*"

#### Create testable software
- clean code
- refactor
- describe what a module does and how it interacts with other modules
- no extra threads than needed
- no swamp of global variables
- no pointer soup
- modules should have unit tests
- support fault injection when modules are interfacing with other modules that can fail
- testable software contain large number of assertions

#### Assertions
- executable check for a property that must be true
- they are not for error handling
- no side effects, no observable change
- no silly assertions should be there
- make code self checking, lead to more effective testing
- make code fail early at a location that is closer to actual bug
- assign blame to correct module/location where error happened
- document assumptions, preconditions, postconditions and invariants
- real libraries use assertions; gcc, LLVM etc.
- advantages of disabling assertions
    - code runs faster
    - code keeps going
- disadvantages of disabling assertions
    - what if code relies on a side-effecting assertions?
    - even in production code, may be better to fail early
- when to use assertions
    - almost always
    - situation when to not use assertions is say in the module for landing the spaceship on mars, if something goes wrong and the assertions are disabled the landing can still be continued

#### Kinds of testing
- White Box
    - tester is using detailed knowledge of the internals of the software in order to construct better test cases
- Black Box
    - tester is not using detailed knowledge of the internals of the software, but instead is testing the software based on how it is supposed to respond to the test cases
- Unit testing
    - testing different units/modules individually
    - can either be white box or black box; mostly white box
- Integration testing
    - taking multiple software modules that have already been unit tested and testing them in combination with each other
- System testing
    - this falls under black box testing
- Differential testing
    - take same input and test different versions of the same software for comparison
- Stress testing
    - here the system is tested at or beyond its normal usage limits
- Random testing
    - here we use the results of the pseudo random number generator to randomly create test inputs and we deliver those to the system under test
- Regression testing
    - it is a type of software testing that verifies that software previously developed and tested still performs correctly even after it was changed or interfaced with other software
