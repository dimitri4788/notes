Sass/SCSS
=========

Sass lets you use features that don't exist in CSS like variables, nesting, mixins, inheritance and etc.

**Generate CSS from Sass**

`sass input.scss output.css`

##Variables
Store information that you want to reuse throughout your stylesheet.

```css
$main-color: #555;

body {
    color: $main-color;
}
```

##Nesting
Nest your CSS selectors in a way that follows the same visual hierarchy of your HTML.

```css
nav {
    ul {
        margin: 0;
        padding: 0;
        list-style: none;
    }

    li {
        display: inline-block;
    }
}
```

##Partials
- Modularize your CSS by creating partial Sass files that contain little snippets of CSS that you can include in other Sass files.
- A partial is simply a Sass file named with a leading underscore.
- You might name it something like _partial.scss.
- The underscore lets Sass know that the file is only a partial file and that it should not be generated into a CSS file.
- Sass partials are used with the `@import` directive.

##Import
If you have a Sass file that you want to import but don’t want to compile to a CSS file, you can add an underscore to the beginning of the filename. This will tell Sass not to compile it to a normal CSS file. You can then import these files without using the underscore.

For example, you might have _colors.scss. Then no _colors.css file would be created, and you can do

```css
/* _colors.scss */

$main-color: #555;
$div-color: #FFF;
$heading-color: #EEE;
```

```
/* base.scss */

@import "colors";

header {
    color: $heading-color;
}
```

##Mixins
- A mixin lets you make groups of CSS declarations that you want to reuse throughout your site.
- You can even pass in values to make your mixin more flexible.
- You can use a mixin as a CSS declaration starting with `@include` followed by the name of the mixin.

A good use of a mixin is for vendor prefixes. Here's an example for border-radius:

```css
@mixin border-radius($radius) {
    -webkit-border-radius: $radius;
    -moz-border-radius: $radius;
    -ms-border-radius: $radius;
    border-radius: $radius;
}

.box { @include border-radius(10px); }
```

##Inheritance/Extend
- Using `@extend` lets you share a set of CSS properties from one selector to another.
- It helps keep your Sass very DRY.

Example:

```css
.message {
    border: 1px solid #ccc;
    padding: 10px;
    color: #333;
}

.success {
    @extend .message;
    border-color: green;
}
```

##Operators
Sass has a handful of standard math operators like +, -, *, /, and %.

Example:

```css
article[role="main"] {
    float: left;
    width: 600px / 960px * 100%;
}
```
