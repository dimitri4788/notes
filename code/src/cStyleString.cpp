#include <iostream>

int main(int argc, char **argv)
{
    /******************
     *** READ NOTE1 ***
     ******************/
    //Create and initialize a C-style string, like this
    char myNameArray[] = "Alex";
    std::cout << myNameArray << std::endl;

    //C-style string symbolic constants using pointers
    const char *myNameSymbolicContant = "Alex";
    std::cout << myNameSymbolicContant << std::endl;


    /******************
     *** READ NOTE2 ***
     ******************/
    int nArray[5] = { 9, 7, 5, 3, 1 };
    char cArray[] = "Hello!";
    const char *name = "Alex";
    std::cout << nArray << std::endl;   // nArray will decay to type int*
    std::cout << cArray << std::endl;   // cArray will decay to type char*
    std::cout << name << std::endl;     // name is already type char*

    /******************
     *** READ NOTE3 ***
     ******************/
    char c = 'Q';
    std::cout << &c << std::endl;

    return 0;
}

/*
 * ******
 * NOTES:
 * ******
*/

/*
 * NOTE1
 * -----
 * While these above two programs operate and produce the same results, C++ deals with the memory allocation for these slightly differently.
 *
 * In the fixed array case, the program allocates memory for a fixed array of length 5,
 * and initializes that memory with the string “Alex\0”. Because memory has been specifically
 * allocated for the array, you’re free to alter the contents of the array.
 *
 * In the symbolic constant case, how the compiler handles this is implementation defined.
 * What usually happens is that the compiler places the string “Alex\0” into read-only memory
 * somewhere, and then sets the pointer to point to it. Multiple string literals with the same
 * content may point to the same location. Because there’s no guarantee that this memory will
 * be writable, best practice is to make sure the string is const.
 * Rule: Feel free to use C-style string symbolic constants if you need read-only strings in your program, but always make them const!
 *
 *
 * NOTE2
 * -----
 *  On the author’s machine, this printed:
 *  003AF738
 *  Hello!
 *  Alex
 *
 * Why did the int array print an address, but the character arrays printed strings?
 *
 * The answer is that std::cout makes some assumptions about your intent. If you pass it
 * a non-char pointer, it will simply print the contents of that pointer (the address that
 * the pointer is holding). However, if you pass it an object of type char* or const char*,
 * it will assume you’re intending to print a string. Consequently, instead of printing the
 * pointer’s value, it will print the string being pointed to instead!
 *
 *
 * NOTE3
 * -----
 *  While this is great 99% of the time, it can lead to unexpected results. Consider the following case:
 *  In this case, the programmer is intending to print the address of variable c. However, &c
 *  has type char*, so std::cout tries to print this as a string! On the author’s machine, this printed:
 *  Q╠╠╠╠╜╡4;¿■A
 *
 * Why did it do this? Well, it assumed &c (which has type char*) was a string. So it printed the 'Q',
 * and then kept going. Next in memory was a bunch of garbage. Eventually, it ran into some memory
 * holding a 0 value, which it interpreted as a null terminator, so it stopped. What you see may
 * be different depending on what’s in memory after variable c.
 *
 * This case is somewhat unlikely to occur in real-life (as you’re not likely to actually want to
 * print memory addresses), but it is illustrative of how things work under the hood, and how programs
 * can inadvertently go off the rails.
 *
 *
 * Source:
 *  http://www.learncpp.com/cpp-tutorial/6-8b-c-style-string-symbolic-constants/
 */
