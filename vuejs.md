Vue.js
======

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



### Directives Modifiers
- .stop - call event.stopPropagation()
- .prevent - call event.preventDefault()
- etc.








#### Sources
