#include <stdio.h>

void func(int x)
{
    printf("%d\n", x);
}

int addInt(int n, int m)
{
    return (n + m);
}

int main()
{
    //Example1
    void (*foo)(int);
    foo = &func;
    //Call func. NOTE: you can also use this syntax (*foo)(2)
    foo(2);
    (*foo)(2);

    //Example2
    int (*functionPtr)(int, int);
    functionPtr = &addInt;
    int sum1 = (*functionPtr)(2, 3); // sum1 == 5
    int sum2 = functionPtr(2, 3);    // sum2 == 5
    printf("%d\n", sum1);
    printf("%d\n", sum2);

    return 0;
}
