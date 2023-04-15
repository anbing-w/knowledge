#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#if 0
int main()
{
    int x[] = {10, 20, 30};
    int *px = x;
    printf("%#p\n", &px);
    printf("%d\n", ++*px); // 优先级相同，自右向左，先取值10，再自增，答案11
    printf("%d\n", *px);
    px = x; // 每次将指针指向的首地址重置
    printf("%#p\n", &px);
    printf("%d\n", (*px)++); // 取值11，自增运算符在右侧，输出值不变，实际值+1
    printf("%d\n", *px);
    px = x;
    printf("%#p\n", &px);
    printf("%d\n", *px++); //*px++ == *(px++)（优先级相同，自右向左）,相当于*x, x=px++,由于自增运算符在右侧，所以x等于px*,*x==*px==12，但实际上现在的px已经自增到后一个单位，首地址改变
    printf("%d\n", *px);   // 所以此时的*px就是后一个单位的值
    px = x;
    printf("%#p\n", &px);
    printf("%d\n", *(px++)); // 先自增，但是运算符在右侧，自增在此不体现，但实际已经向右移一个单位，首地址改变
    printf("%d\n", *px);     // 实际移了一个单位
    px = x;
    printf("%#p\n", &px);
    printf("%d\n", *++px); // 先自增，自增运算符在左，自增效果体现
    printf("%d\n", *px);
    return 0;
}
#endif

/***
 * 判断返回值
int fun(int *p)
{
    return p[6];
}

void main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b;
    b = fun(&a[2]);
    printf("%d\n", b);
}
 */
/**
 * 局部变量的作用域只在该变量所在的局部范围
 */
#if 0
char *GetMemory(void) // line 1
{
    char *p = (char *)malloc(10); // line 2
    return p;                     // line 3
}

void main(void)
{
    char *str = NULL;           // line 3
    str = GetMemory();          // line 4
    strcpy(str, "hello world"); // line 5
    printf("%s",str);                // line 6
}
#endif

#if 0
//判断是否为空指针，防止解引用错误，NULL的话一般指向地址为0，向地址零赋值可能会产生莫名其妙的错误
static int data[100];
void fun(int i , int *value)
{
    assert(value);
    data[i] = *value;
    *value = 0;
}
#endif
