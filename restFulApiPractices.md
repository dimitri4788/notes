RESTful API Guidelines
======================

Some best practices and guidelines to create an efficient RESTful API with HTTP

Structure Of A URL
------------------
Refer to this document for information on URLs: [URLs](https://github.com/deep4788/notes/blob/master/urls.md)

Rules
-----
- Create a uniform interface by mapping HTTP methods to CRUD (Create, Read, Update, Delete)
    - HTTP methods = POST, GET, PUT, DELETE
        - Create = POST
        - Read = GET
        - Update = PUT
        - Delete = DELETE
- Understand the difference between a URI and a Resource
    - GET: http:/test.com/user/1; method = Get, URI = http:/test.com/user/1, resource = user/1 is a user
- Understand the difference between a resource and a representation
    - Calling GET: http:/test.com/user/1 will return a representation of the resource user:1
    - A representation has a format (XML, JSON , XHTML etc), and a language.
- Keep the number of resources low
    - The resource names should map conceptual domain entities; they should map to objects (name them as nouns), not actions on the objects
    - If you want to declare a user as a subscriber, you don’t need to add a resource called subscribe. Just add subscribe as an attribute to user's representation
- Create addressability by mapping a URI to each resource, possibly each representation (test.com/user.xml, test.com/user.json)
- Name resources and representations carefully
    - Use forward slashes to show child objects, with a resource for each item
        - /events – exposes all events
        - /events/concerts – exposes all concerts
        - /events/concerts/1 – exposes a concert with id of 1
    - Use semi-colons where there is no obvious sequence
        - /events/locations/the-concorde-2;the-brighton-dome – is a search for 2 event locations
    - Use comma’s when the order matters but they are not child items
        - /events/locations/25.9,22.5 – is a lat/long search
- Use POST for creating, not editing
    - When you POST you POST to an unknown resource -> (POST: /user)
    - How should you handle the following situation -> POST: /user/1
        - You could update it with the new data, or you could respond with a already created code, and force the use of PUT
        - Using PUT is recommended
- Consider the use of overloaded POST only to handle situations where PUT and DELETE are unavailable
    - A true REST API wouldn’t do this, but sometimes you need to be flexible
    - One way of doing this is to define in the API the actual call you want to use to replace POST:
        - POST: /user/1?method=put
        - POST: /user/1?method=delete
    - The API can then convert the POST call into the appropriate method, and funnel it into the same route
- GET and HEAD should only ever fetch data, never alter or delete it
- Allow for multiple identical PUT or DELETE requests, without side effects
    - If you are updating the price of a widget in a PUT request, don’t allow anything like
        - price: +1
        - price: -2
    - Instead, only accept a new price:
        - price: 3.99
- Use HTTP Response Codes
    - Don’t just return a 200 response with an error description if something is wrong
- Handle and use meta-data in HTTP Headers, such as Accept-Encoding, Host, User-Agent, Content-Length etc.
- REST is stateless, so don’t handle state in your API
    - REST API’s must be stateless. Every call requiring authentication should provide the authentication and never a session key
    - When you attempt to handle state in your API you create a nightmare of sessions and session handling on the API side, and create lots of repetitive work for each service connecting to your API who has to potentially always handle the case where the session has expired. Handling state will slow down your API and all clients using it
    - Stateless API’s are easier to scale, more reliable and simpler to use.
- REST is cacheable 1 – allow clients to GET only updated resources via HTTP
    - If your clients are repeatedly requesting the same data you are unnecessarily slowing all applications down, increasing bandwidth from the server to the clients and wasting computation power. Instead, use HTTP to handle this
    - The easy way with Last-Modified
        - Server provides a Last-Modified header with each GET call, the date the resource was last modified.
        - Clients can now GET with the header If-Unmodified-Since containing the latest Last-Modified value
        - The server either updates the resource if the Last-Modified value for the resource matches the one in If-Unmodified-Since, or respond with a 304 Not Modified.
    - Get more precise with ETags
        - There is a risk here where more than one person can update data, that the data updated again within the same second. This is why you can also use ETags.
        - Server provides an ETag (more on how to create ETags) which represents the resources current state, with each GET call
        - Clients can now GET with the header If-None-Match containing the latest ETag value
        - The server either responds with the resource if the ETags differ, or respond with a 304 Not Modified
    - However, ETags are more costly to generate than Last-Modified, and should be considered carefully
- REST is cacheable 2 – prevent accidental simultaneous updates of the same resource via HTTP
    - similar as last bullet
- Use the HEAD method to allow the client to manage its bandwidth better
    - The HEAD method for an resource should return a meta-data only representation of the resource
    - "HEAD: /user" should return everything "GET: /user" would except the entity-body
- Version your API, and never change released features
    - Each URI should begin with a version number: /v1.0/user
    - If you remove anything from the representation being returned for user, or change the rules about what you accept, you need to increase the version number – don’t just change the current representation: /v2.0/user
    - This prevents your clients from breaking!

### Sources
- http://mark-kirby.co.uk/2013/creating-a-true-rest-api/
- https://www.ibm.com/developerworks/webservices/library/ws-restful/
