#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    //This feature allows you to use variables for formatting format specifiers themselves
    int a = 3;
    float b = 6.412355;
    printf("%.*f\n", a, b);

    //Using #if 0 and #endif to comment out blocks of code
    printf("This will be printed.\n");
#if 0
    printf("This will not be printed.\n");
#endif

    //Cool built-in macros and identifiers
    printf("Counter: %d\n", __COUNTER__);
    printf("Counter: %d\n", __COUNTER__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    printf("FileName: %s\n", __FILE__);
    printf("LineNumber: %d\n", __LINE__);
    printf("FunctionName: %s\n", __func__);

    //But nothing of what you do in the loop seems to execute, it's because the ANSI C standard
    //defines that whenever there is a comparison between a qualified and a non qualified type,
    //the non qualified type gets promoted to a type of the same type, but also inherits the qualifiers
    //of the other quantity.
    //Anyway, in other words, i here is promoted to an unsigned int,and so its value (-1), which is coded in
    //two's complement is interpreted as an unsigned int. Now -1 as an unsigned is 00000001 -> 11111110 + 1 = 11111111 i.e.
    //a very large positive number, actually the largest int. Note that I have only used eight digits for the sake
    //of simplicity. Its also very early in the morning and I haven't slept.
    unsigned int u = 10; 
    int i = -1; 
    if(i <= u)
    { 
        printf("This will be printed.");
    }

    return 0;
}
