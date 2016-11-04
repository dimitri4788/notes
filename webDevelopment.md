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


CSS
---
- Units: EM, PX, PT, CM, IN, MM
- The units have nothing to do with the properties (font-size, color etc.), but everything with the output media: screen or paper
- Recommended
    - Screen: em, px, %
    - Paper: em, cm, mm, in, pt, pc, %
- em: mobile device friendly unlike px which are fixed-size
- Generally, 1em = 12pt = 16px = 100%
- At-Rules: @import, @media, and @font-face
    - They can be used to import other CSS files, apply CSS to a particular media, or embed funkysexy uncommon fonts
    - **@import url(morestyles.css)**
        - This is used to bolt another stylesheet onto your existing one
        - @import rules must be placed at the top of a stylesheet, before any other rules
    - **@media xyz**
        - It can be used to apply styles to a specific media, such as print
        - Values that follow "@media" can include screen, print, projection, handheld, and all, or a comma-separated list of more than one
    - **@font-face**
        - It is a technique for embedding fonts in a web page so that a typeface can be used even if it isn’t sitting on the user’s computer

#### Libraries
- normalize.min.css
- bootstrap.min.css
- font-awesome.min.css

#### Links
- [CSS Tutorials](http://www.htmldog.com/guides/css/)
- [CSS Selectors](http://www.htmldog.com/references/css/selectors/)
- [Google Fonts](https://fonts.google.com/)
- [Typekit (purchase fonts)](https://typekit.com/)

JavaScript
----------


#### Frameworks
- [Node.js](https://nodejs.org/en/)
- [Express.js](http://expressjs.com/)
- [Bootstrap](http://www.w3schools.com/bootstrap/default.asp)


Useful Tools/Links
------------------
- [Modernizr](https://modernizr.com/): Modernizr tells you what HTML, CSS and JavaScript features the user’s browser has to offer.


