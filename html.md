HTML
====

- A link can also send a user to another part of the same page they are on. You can add an id attribute to just about any tag, for example `<h2 id="moss">Moss</h2>`, and then link to it by using something like this: `<a href="#moss">Go to moss</a>`. Selecting this link will scroll the page straight to the element with that ID.
- Difference between **span** and **div** is that a span element is in-line and usually used for a small chunk of HTML inside a line (such as inside a paragraph) whereas a div (division) element is block-line (which is basically equivalent to having a line-break before and after it) and used to group larger chunks of code.
- Interesting tags (not so often used)
    - abbreviations (abbr), quotations (q), computer code (code), cite, pre
    - address, dfn, bdo, del, ins
- Sectioning tags
    - article, section, header, footer, aside, figure, nav (navigation)
- Conditional comments: `<!--[if IE]><link href="stupidie.css" rel="stylesheet"><![endif]-->`
    - Everything between <!--[if IE]> and <![endif]--> will be picked up by Internet Explorer

#### Vendor Prefix
Typically the vendors use these prefixes:  

- -webkit- (Chrome, Safari, newer versions of Opera.)
- -moz- (Firefox)
- -o- (Old versions of Opera)
- -ms- (Internet Explorer)

Vendors also use prefixes on API. On interfaces, they typically use:  

- Webkit (Chrome, Safari, newer versions of Opera.)
- Moz (Firefox)
- O (Old versions of Opera)
- MS (Internet Explorer)

On properties and methods, they typically use:  

- webkit (Chrome, Safari, newer versions of Opera.)
- moz (Firefox)
- o (Old versions of Opera)
- ms (Internet Explorer)

#### BOM
**Browser Object Model**

The **window** object represents an open window in a browser. All global JavaScript objects, functions, and variables automatically become members of the window object.

Global variables are properties of the window object. Global functions are methods of the window object. Even the document object (of the HTML DOM) is a property of the window object:

#### DOM
**Document Object Model**

When a web page is loaded, the browser creates a Document Object Model of the page.

The HTML DOM is a standard object model and programming interface for HTML. It defines:

- The HTML elements as objects
- The properties of all HTML elements
- The methods to access all HTML elements
- The events for all HTML elements

In other words: The HTML DOM is a standard for how to get, change, add, or delete HTML elements.

#### Links
- [HTML Tutorials](http://www.htmldog.com/guides/html/)
- [`<head>` Cheat Sheet](http://gethead.info/)

Useful Tools/Links
------------------
- [Modernizr](https://modernizr.com/): Modernizr tells you what HTML, CSS and JavaScript features the user’s browser has to offer.
