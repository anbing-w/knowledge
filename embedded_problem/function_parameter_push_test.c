#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 压入栈的地址是从高到底，函数的参数入栈顺序是从右到左
 * 
 * @param a 
 * @param b 
 * @param c 
 */
void stackPushTest(int a, int b, int c)
{
    printf("a:%#p\n", (unsigned int)&a);
    printf("b:%#p\n", (unsigned int)&b);
    printf("c:%#p\n", (unsigned int)&c);
}


int main(int argc, char** argv)
{
    char *ptr;
    if ((ptr = (char*)malloc(-1)) == NULL)
    {
        puts("GOT a null pointer\n");
    }
    else{
        puts("GOT a valid pointer\n");
    }
}
