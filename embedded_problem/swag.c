#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define NDBUG
#include <assert.h>

void swap(int *p1, int *p2)
{
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void swag_corr2(int *p1, int *p2)
{
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
}
//参数 a 和 b 采用的是按值传递的方式，也就是说，在函数中对参数进行修改不会影响到函数外部的变量。
/*值传递的特点是单向传递，即主调函数调用时给形参分配存储单元，
**把实参的值传递给形参，在调用结束后，形参的存储单元被释放，
**而形参值的任何变化都不会影响到实参的值，实参的存储单元仍保留并维持数值不变。
*/
void swap_err1(int p1, int p2) // 未传递地址
{
    int tmp = p1;
    p1 = p2;
    p2 = tmp;
    printf("[swap_err2] in  p1 = %d, p2 = %d\n\n", p1, p2);
}
void swap_err2(int *p1, int *p2) // 未解引用
{
    int *tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}

void swap_err3(int *p1, int *p2) // 指针未初始化
{
    int *tmp; //野指针，会产生莫名其妙的问题
    *tmp = *p1;
    *p1 = *p2;
    *p2 = *tmp;
}

int main()
{
    int a = 10, b = 20;

    printf("[swap] before a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("[swap] later  a = %d, b = %d\n\n", a, b);

    a = 10, b = 20;
    printf("[swap2] before a = %d, b = %d\n", a, b);
    swag_corr2(&a, &b);
    printf("[swap2] later  a = %d, b = %d\n\n", a, b);

    a = 10, b = 20;
    printf("[swap_err1] before a = %d, b = %d\n", a, b);
    swap_err1(a, b);
    printf("[swap_err1] later  a = %d, b = %d\n\n", a, b);

    a = 10, b = 20;
    printf("[swap_err2] before a = %d, b = %d\n", a, b);
    swap_err2(&a, &b);
    printf("[swap_err2] later  a = %d, b = %d\n\n", a, b);

/*     a = 10, b = 20;
    printf("[swap_err3] before a = %d, b = %d\n", a, b);
    swap_err3(&a, &b);
    printf("[swap_err3] later  a = %d, b = %d\n\n", a, b); */

    return 0;
}
