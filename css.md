CSS
===

- Units (EM, PX, PT, CM, IN, MM, etc)
    - There are two types of length units: relative and absolute
        - Relative length units specify a length relative to another length property. Relative length units scales better between different rendering mediums
        - The absolute length units are fixed and a length expressed in any of these will appear as exactly that size. Absolute length units are not recommended for use on screen, because screen sizes vary so much. However, they can be used if the output medium is known, such as for print layout.
    - Distance, Position & Size: px, em, rem, %
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
- Pseudo Selector
    - To select state of an element, for example
        - Style an element when a user mouses over it
        - Style visited and unvisited links differently
        - Style an element when it gets focus

        ```
        selector:pseudo-class {
            property:value;
        }
        ```

### Libraries/Frameworks
- normalize.min.css
- bootstrap.min.css
- font-awesome.min.css
- blueprint
- unsemantic
- bluetrip
- elasticss
- bootstrap
- foundation
- kube
- groundwork
- semantic ui
- Purecss

### Links
- [CSS Tutorials](http://www.htmldog.com/guides/css/)
- [CSS Selectors](http://www.htmldog.com/references/css/selectors/)
- [Google Fonts](https://fonts.google.com/)
- [Typekit (purchase fonts)](https://typekit.com/)
