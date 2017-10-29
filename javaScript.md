JavaScript
==========

**ECMAScript**: ECMAScript trademarked scripting-language specification standardized by Ecma International. It was based on JavaScript, which now tracks ECMAScript. It is commonly used for client-side scripting on the World Wide Web.

ECMAScript is supported in many applications, especially Web browsers, where it is implemented by JavaScript, or, in the case of Internet Explorer, JScript.

Latest edition as of 10/15/2016 is 6, ES6 or ECMAScript 2015.

### Concepts
- **==** operator checks only for values, while **===** (equality operator) expects equality in both type and value
- JavaScript objects cannot be compared
    - `var x = new String("John"); var y = new String("John")`
    - (x == y) is false because x and y are different objects
    - (x == x) is true because both are the same object
- String methods
    - length, indexOf(...), lastIndexOf(...), search(...), slice(start, end), substring(start, end), substr(start, length), replace(...) etc.
- How to Recognize an Array
    - `var fruits = ["Banana", "Orange", "Apple", "Mango"]`
    - `Array.isArray(fruits)`   // returns true
    - `fruits instanceof Array` // returns true
    - `fruits.constructor.toString().indexOf("Array") > -1` //returns true
- JavaScript Data Types
    - Primitive values are: strings ("John Doe"), numbers (3.14), true, false, null, and undefined
    - 5 different data types that can contain values:
        - string
        - number
        - boolean
        - object
        - function
    - 3 types of objects:
        - Object
        - Date
        - Array
    - 2 data types that cannot contain values:
        - null
        - undefined
- Function arguments are passed by value
- Objects are passed by reference

#### JavaScript Debugging

- `debugger`
  - add in the code and the debugger will stop there
- display data in table format using `console.table(object);`
- Benchmark loops using `console.time()` and `console.timeEnd()`

#### DOM Related
- Getting an Element
    - **document.getElementById**: returns a single Node
    - **document.getElementsByTagName**: returns a NodeList
    - **document.getElementsByClassName**: returns a NodeList
    - **document.querySelector**: returns a single Node
    - **document.querySelectorAll**: returns a NodeList

#### Frameworks
- [Node.js](https://nodejs.org/en/)
- [Express.js](http://expressjs.com/)
- [Bootstrap](http://www.w3schools.com/bootstrap/default.asp)

#### Links
- [JavaScript Tutorials](http://www.htmldog.com/guides/javascript/)
- [Airbnb JavaScript Style Guide](https://github.com/airbnb/javascript)
- [JavaScript Promises](https://developers.google.com/web/fundamentals/getting-started/primers/promises)


Useful Tools/Links
------------------
- [Modernizr](https://modernizr.com/): Modernizr tells you what HTML, CSS and JavaScript features the user’s browser has to offer.


