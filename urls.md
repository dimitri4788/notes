Structure Of A URL
==================

`<scheme>://<username>:<password>@<host>:<port>/<path>;<parameters>?<query>#<fragment>`

**scheme**: this basically specifies the protocol to use to access the resource addressed by the URL (e.g. http, ftp). The scheme must start with a letter and is separated from the rest of the URL by the first : (colon) character. That's right, the // is not part of the separator but is infact the beginning of the next part of the URL.

**username**: this along with the password, the host and the port form what's known as the authority part of the URL. Some schemes require authentication information to access a resource this is the username part of that authentication information. The username and password are very common in ftp URLs, they are less common in http URLs, but you do come across them fairly regularly.

**password**: the other part of the authentication information for a URL, it is separated from the username by another : (colon) character. The username and password will be separated from the host by an @ (at) character. If you don't supply the username and password and the URL you're trying to access requires one, the application you're using (e.g. browser) will supply some defaults.

**host**: it is one of the components that makes up the authority part of the URL. The host can be either a domain name or an IP address, as we all should know the domain name will resolve to an IP address (via a DNS lookup) to identify the machine we're trying to access.

**port**: it basically tells us what network port a particular application on the machine we're connecting to is listening on. As we all know, for HTTP the default port is 80, if the port is omitted from an http URL, this is assumed.

**path**: is separated from the URL components preceding it by a / (slash) character. A path is a sequence of segments separated by / characters. The path basically tells us where on the server machine a resource lives. Each of the path segments can contain parameters which are separated from the segment by a ; (semi-colon) character e.g.:
`http://www.blah.com/some;param1=foo/crazy;param2=bar/path.html`
The URL above is perfectly valid, although this ability of path segments to hold parameters is almost never used

**parameters**: these can also appear after the path but before the query string, also separated from the rest of the URL and from each other by ; characters e.g.:
`http://www.blah.com/some/crazy/path.html;param1=foo;param2=bar`
They are not very common

**query**: these on the other hand are very common. This is the preferred way to send some parameters to a resource on the server. These are key=value pairs and are separated from the rest of the URL by a ? (question mark) character and are normally separated from each other by & (ampersand) characters. What you may not know is the fact that it is legal to separate them from each other by the ; (semi-colon) character as well. The following URLs are equivalent:
`http://www.blah.com/some/crazy/path.html?param1=foo&param2=bar`
`http://www.blah.com/some/crazy/path.html?param1=foo;param2=bar`

**fragment**: this is an optional part of the URL and is used to address a particular part of a resource. We usually see these used to link to a particular section of an html document. A fragment is separated from the rest of the URL with a # (hash) character. When requesting a resource addressed by a URL from a server, the client (i.e. browser) will usually not send the fragment to the server (at least not where HTTP is concerned). Once the client has fetched the resource, it will then use the fragment to address the relevant part.

Special Characters In URLs
--------------------------

There are several sets of characters when it comes to URLs. The characters that have special meaning within a URL are known as **reserved characters**, these are:
`";" | "/" | "?" | ":" | "@" | "&" | "=" | "+" | "$" | ","`

If a part of a URL (such as a query parameter), is likely to contain one of these characters, it should be escaped before being included in the URL.

--

The second set of characters to be aware of is the **unreserved set**. It is made up of the following characters
`"-" | "_" | "." | "!" | "~" | "*" | "'" | "(" | ")"`

The characters can be included as-is in any part of the URL (note that they may not be allowed as part of a particular component of a URL). This basically means you don't need to encode/escape these characters when including them as part of a URL. You CAN escape them without changing the semantics of a URL, but it is not recommended.

--

The third set to be aware of is the **'unwise' set**, i.e. it is unwise to use these characters as part of a URL. It is made up of the following characters
```"{" | "}" | "|" | "\" | "^" | "[" | "]" | "`"```

These characters are considered unwise to use in a URL because gateways are known to sometimes modify such characters, or they are used as delimiters. That doesn't mean that these characters will always be modified by a gateway, but it can happen. So, if you include these as part of a URL without escaping them, you do this at your own risk. What it really means is you should always escape these characters if a part of your URL (i.e. like a query param) is likely to contain them.

--

The last set of characters is the **excluded set**. It is made up of all ASCII control characters, the space character as well the following characters (known as delimiters)
`"<" | ">" | "#" | "%" | '"'`

The control characters are non-printable US-ASCII characters (i.e. hexadecimal 00-1F as well as 7F). These characters must always be escaped if they are included in a component of a URL. Some, such as # (hash) and % (percent) have special meaning within the context of a URL (they can really be considered equivalent to the reserved characters). Other characters in this set have no printable representation and therefore escaping them is the only way to represent them. The <, > and “ characters should be escaped since these characters are often used to delimit URLs in text.

To URL encode/escape a character we simply append its 2 character ASCII hexadecimal value to the % character. So, the URL encoding of a space character is %20. The % character itself is encoded as %25.



### Sources
- http://www.skorks.com/2010/05/what-every-developer-should-know-about-urls/
