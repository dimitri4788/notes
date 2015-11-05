#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void func(int x)
{
    printf("%d\n", x);
}

int addInt(int n, int m)
{
    return (n + m);
}

int main(int argc, char **argv)
{
    //Example1
    void (*foo)(int); //Declare a function pointer
    foo = &func; //To initialize a function pointer, you must give it the address of a function in your program
    foo(2); //To call the function pointed to by a function pointer, you treat the function pointer as though it were the name of the function you wish to call
    (*foo)(2); //NOTE: you can also use this syntax. It is same as foo(2)

    //Example2
    int (*functionPtr)(int, int);
    functionPtr = &addInt;
    int sum1 = (*functionPtr)(2, 3); // sum1 == 5
    int sum2 = functionPtr(2, 3);    // sum2 == 5 with different syntax
    printf("%d\n", sum1);
    printf("%d\n", sum2);

    return 0;
}
