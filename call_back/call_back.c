#include <stdio.h>


#ifdef __HAVE_PARA_
int Callback_1() // Callback Function 1
{
    printf("Hello, this is Callback_1 \r\n");
    return 0;
}

int Callback_2() // Callback Function 2
{
    printf("Hello, this is Callback_2 \r\n");
    return 0;
}

int Callback_3() // Callback Function 3
{
    printf("Hello, this is Callback_3 \r\n");
    return 0;
}

int Handle(int (*Callback)())
{
    printf("Entering Handle Function. \r\n");
    Callback();
    printf("Leaving Handle Function. \r\n");
}

int main()
{
    printf("Entering Main Function. \r\n");
    Handle(Callback_1);
    Handle(Callback_2);
    Handle(Callback_3);
    printf("Leaving Main Function. \r\n");
    return 0;
}
#else
int Callback_1(int x) // Callback Function 1
{
    printf("Hello, this is Callback_1: x = %d \r\n", x);
    return 0;
}

int Callback_2(int x) // Callback Function 2
{
    printf("Hello, this is Callback_2: x = %d \r\n", x);
    return 0;
}

int Callback_3(int x) // Callback Function 3
{
    printf("Hello, this is Callback_3: x = %d \r\n", x);
    return 0;
}

int Handle(int y, int (*Callback)(int))
{
    printf("Entering Handle Function. \r\n");
    Callback(y);
    printf("Leaving Handle Function. \r\n");
}

int main()
{
    int a = 2;
    int b = 4;
    int c = 6;
    printf("Entering Main Function. \r\n");
    Handle(a, Callback_1);
    Handle(b, Callback_2);
    Handle(c, Callback_3);
    printf("Leaving Main Function. \r\n");
    return 0;
}

#endif

