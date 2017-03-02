Vue.js
======

- Created getter and setter for data properties; the data properties are reactive, Vue.js watches for the changes
- Internally, Vue.js uses a queue which acts as a buffer for all of the data properties changes that have been applied within the same event loop; it does so asynchronously, even though it looks synchronous
    - This event loop checks for the changes to the data that haven't been applied to the DOM yet and applied them. It every now and then kicks in apply the changes
- Uses virtual DOM; sits between DOM and the Vue instance

Basic Syntax:

```
#html
<div id="app-id">
    <h1>{{ age * 2 }}</h1>
    <p>Firstname: {{ name.split(" ")[0] }}</p>
    <p>Address: {{ getAddress() }}</p>
</div>


#js
new Vue({
    el: "#app-id",
    data: {
        age: 28,
        name: "Deep Aggarwal",
        address: "Chicago, IL",
        myUrl: "http://thisisawebsite.com"
    },
    method: {
        getAddress: function() {
            return this.address;
        }
    }
});
```

Mathematical Operation: `{{ age * 2 }}`  
Boolean expression: `{{ age > 60 ? "Old" : "Young" }}`

## Directives
**v-bind**: Dynamically bind one or more attributes, or a component prop to an expression

```
<img v-bind:src="imageSrc">
<div v-bind="{ id: someProp, 'other-attr': otherProp }"></div>
<a v-bind:href="myUrl"></a>
```

**v-on**: Attaches an event listener to the element. The event type is denoted by the argument. The expression can either be a method name or an inline statement, or simply omitted when there are modifiers present

```
<button v-on:click="doThis"></button>

#Passing event object as argument
<button v-on:click="doThat('hello', $event)"></button>

<form v-on:submit.prevent></form>
<input v-on:keyup.13="onEnter">
```

**v-model**: Create a two-way binding on a form input element or a component

```
<input v-model="message" placeholder="edit me">
<p>Message is: {{ message }}</p>
```

**v-html**: Updates the element's innerHTML. Note that the contents are inserted as plain HTML - they will not be compiled as Vue templates

NOTE: Dynamically rendering arbitrary HTML on your website can be very dangerous because it can easily lead to XSS attacks. Only use v-html on trusted content and never on user-provided content

```
<div v-html="html"></div>
```

**v-once**: Render the element and component once only. On subsequent re-renders, the element/component and all its children will be treated as static content and skipped. This can be used to optimize update performance

```
<span v-once>This will never change: {{msg}}</span>
```

**v-if and v-else and v-else-if**: Conditional Rendering

```
<div v-if="type === 'A'">
    A
</div>
<div v-else-if="type === 'B'">
    B
</div>
<div v-else-if="type === 'C'">
    C
</div>
<div v-else>
    Not A/B/C
</div>
```

**v-show**: Toggle's the element's display CSS property based on the truthy-ness of the expression value 

```
<p v-show="isSet">This is Set.</p>
<p v-show="!isSet">This is not Set.</p>
```

**v-cloak**: This directive will remain on the element until the associated Vue instance finishes compilation. Combined with CSS rules such as [v-cloak] { display: none }, this directive can be used to hide un-compiled mustache bindings until the Vue instance is ready

```
#CSS
[v-cloak] {
    display: none;
}

#HTML
<div v-cloak>
    {{ message }}
</div>

#The <div> will not be visible until the compilation is done.

```

**v-for**: Looping

```
<div v-for="item in items">
    {{ item.text }}
</div>

or

<div v-for="(item, index) in items"></div>
<div v-for="(val, key) in object"></div>
<div v-for="(val, key, index) in object"></div>

#Looping through number ranges
<div v-for="n in 10"> {{ n }} </div> #This will create 10 divs with text from 1 - 10
```

### Directives Modifiers
- .stop - call event.stopPropagation()
- .prevent - call event.preventDefault()
- etc.

## Computed Properties
Computed properties are cached, and only re-computed on reactive dependency changes

```
new Vue({
    data: { a: 1 },
    computed: {
        aDouble: function () {
            return this.a * 2
        }
    }
});
```

##Watch data for changes
An object where keys are expressions to watch and values are the corresponding callbacks. The value can also be a string of a method name, or an Object that contains additional options

```
var vm = new Vue({
    data: {
        a: 1,
        b: 3
    },
    watch: {
        a: function (val, oldVal) {
            console.log('new: %s, old: %s', val, oldVal)
        },
        // deep watcher
        b: {
            handler: function (val, oldVal) { /* ... */ },
            deep: true
        }
    }
});
vm.a = 2 // -> new: 2, old: 1
```

##Adding watchers dynamically

```
var vm = new Vue({
    data: {
        age: "28",
        person: {
            name: {
                firstname: "Andy",
                lastname: "Smith"
            }
        }
    }
});

//Watching a property
vm.$watch("age", function(newValue, oldValue) {
    console.log("Value of age changed from " + oldValue + " to " + newValue);
});

//Watching an object
vm.$watch("person.name", function(newValue, oldValue) {
    console.log("Value of person.name changed from " + oldValue + " to " + newValue);
}, { deep: true });

NOTE: We can watch computed properties too
```










#### Sources
