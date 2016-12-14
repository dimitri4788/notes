Web Development
===============

**ECMAScript**: ECMAScript trademarked scripting-language specification standardized by Ecma International. It was based on JavaScript, which now tracks ECMAScript. It is commonly used for client-side scripting on the World Wide Web.

ECMAScript is supported in many applications, especially Web browsers, where it is implemented by JavaScript, or, in the case of Internet Explorer, JScript.

Latest edition as of 10/15/2016 is 6, ES6 or ECMAScript 2015.

HTML
----
- A link can also send a user to another part of the same page they are on. You can add an id attribute to just about any tag, for example `<h2 id="moss">Moss</h2>`, and then link to it by using something like this: `<a href="#moss">Go to moss</a>`. Selecting this link will scroll the page straight to the element with that ID.
- Difference between **span** and **div** is that a span element is in-line and usually used for a small chunk of HTML inside a line (such as inside a paragraph) whereas a div (division) element is block-line (which is basically equivalent to having a line-break before and after it) and used to group larger chunks of code.
- Interesting tags (not so often used)
    - abbreviations (abbr), quotations (q), computer code (code), cite, pre
    - address, dfn, bdo, del, ins
- Sectioning tags
    - article, section, header, footer, aside, figure, nav (navigation)
- Conditional comments: `<!--[if IE]><link href="stupidie.css" rel="stylesheet"><![endif]-->`
    - Everything between <!--[if IE]> and <![endif]--> will be picked up by Internet Explorer

#### Links
- [HTML Tutorials](http://www.htmldog.com/guides/html/)

JavaScript
----------
- Getting an Element
    - **document.getElementById**: returns a single Node
    - **document.getElementsByTagName**: returns a NodeList
    - **document.getElementsByClassName**: returns a NodeList
    - **document.querySelector**: returns a single Node
    - **document.querySelectorAll**: returns a NodeList
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


