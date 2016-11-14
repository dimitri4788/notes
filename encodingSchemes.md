Character Encoding
==================

- ASCII
    - It defines 128 characters, which map to the numbers 0–127.
- UNICODE
    - It defines (less than) 2^21 characters, which map to numbers 0–2^21 (though not all numbers are currently assigned, and some are reserved).
    - Unicode is a superset of ASCII, and the numbers 0–128 have the same meaning in ASCII as they have in Unicode. For example, the number 65 means "Latin capital 'A'".
    - The Unicode standard describes how characters are represented by code points. A code point is an integer value, usually denoted in base 16.
    - Because Unicode characters don't generally fit into one 8-bit byte, there are numerous ways of storing Unicode characters in byte sequences, such as UTF-32 and UTF-8; ways to encode Unicode strings as bytes.

<br>

- UTF-8 uses the following rules:
    - If the code point is <128, it’s represented by the corresponding byte value.
    - If the code point is between 128 and 0x7ff, it’s turned into two byte values between 128 and 255.
    - Code points >0x7ff are turned into three- or four-byte sequences, where each byte of the sequence is between 128 and 255.
- UTF-8 has several convenient properties:
    - It can handle any Unicode code point.
    - A Unicode string is turned into a string of bytes containing no embedded zero bytes. This avoids byte-ordering issues, and means UTF-8 strings can be processed by C functions such as strcpy() and sent through protocols that can’t handle zero bytes.
    - A string of ASCII text is also valid UTF-8 text.
    - UTF-8 is fairly compact; the majority of code points are turned into two bytes, and values less than 128 occupy only a single byte.
    - If bytes are corrupted or lost, it’s possible to determine the start of the next UTF-8-encoded code point and resynchronize. It’s also unlikely that random 8-bit data will look like valid UTF-8.
- There’s also a UTF-16 encoding, but it’s less frequently used than UTF-8.
- The Difference Between Unicode and UTF-8
    - Unicode is a character set. UTF-8 is encoding.
    - Unicode is a list of characters with unique decimal numbers (code points). A = 65, B = 66, C = 67, ....
        - This list of decimal numbers represent the string "hello": 104 101 108 108 111
    - Encoding is how these numbers are translated into binary numbers to be stored in a computer:
        - UTF-8 encoding will store "hello" like this (binary): 01101000 01100101 01101100 01101100  01101111
    - Encoding translates numbers into binary. Character sets translates characters to numbers.

### Sources
- http://www.skorks.com/2009/08/different-types-of-encoding-schemes-a-primer/
