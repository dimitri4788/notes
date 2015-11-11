#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int luckyNumber = 7;

    int *singlePointer;
    int **doublePointer;

    singlePointer = &luckyNumber;
    doublePointer = &singlePointer;

    printf("Address of luckyNumber (&luckyNumber)     : %p\n", &luckyNumber);
    printf("Address of luckyNumber (singlePointer)    : %p\n", singlePointer);
    printf("Address of luckyNumber (*doublePointer)   : %p\n", *doublePointer);

    printf("Value of luckyNumber (luckyNumber)        : %d\n", luckyNumber);
    printf("Value of luckyNumber (*singlePointer)     : %d\n", *singlePointer);
    printf("Value of luckyNumber (**doublePointer)    : %d\n", **doublePointer);

    printf("Address of singlePointer (&singlePointer) : %p\n", &singlePointer);
    printf("Address of singlePointer (doublePointer)  : %p\n", doublePointer);

    printf("Address of doublePointer (&doublePointer) : %p\n", &doublePointer);

    return 0;
}
