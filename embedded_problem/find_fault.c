#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// #define NDEBUG
#include <assert.h>

#if 1
/* //第三题unsigned char的取值范围是0-255永远也到不了500，所以下面的为死循环
#define Max_CB 500
void LmiQueryCSmd(StructMSgCB *pmsg)
{
    unsigned char ucCmdNum;
    ...... for (ucCmdNum = 0; ucCmdNum < Max_CB; ucCmdNum++)
    {
        ......;
    }
} */

#define LEN_MAX 256
/**
 * @brief 整型提升
 *
 */
void foo(void)
{
    unsigned int a = 6;
    unsigned long c;
    int b = -20;
    c = a + b;
    (a + b > 6) ? puts("> 6") : puts("<= 6");
    printf("%ld\n", (unsigned int)(a + b));
    printf("%ld\n", c);
}

char getChar(int x, int y)
{
    char c;
    unsigned int a = x;
    unsigned int b = a + y;
    (a + y > 10) ? (c = 1) : (c = 2);
    printf("%d\n", a + y);
    return c;
}

//
int main()
{
    /*   第一题
        int a[5] = {1, 2, 3, 4, 5};
        int *ptr = (int *)(&a + 1);
        printf("%d,%d", *(a + 1), *(ptr - 1)); */
    /*    // 第二题，三维数组内成员初始化为0
        int a[2][3][4], i, j, k;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
            {
                for (k = 0; k < 4; k++)
                {
                    a[i][j][k] = 0;
                }
            }
        } */

    foo();

    // char c1 = getChar(7, 4);
    // char c2 = getChar(7, 3);
    // char c3 = getChar(7, -8);
    // char c4 = getChar(7, -8);

    // printf("c1=%d\n", c1);
    // printf("c2=%d\n", c2);
    // printf("c3=%d\n", c3);
    // printf("c4=%d\n", c4);

    return 0;
}
#endif
