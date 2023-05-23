#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// #define NDEBUG //必须放在assert.h头文件之前 否则不起作用

#include <assert.h>
#include <time.h>

#define __COUNT_BIT__

#define NUMBER(x) (sizeof(x) / sizeof(x[0])) // 已知数组x，使用宏求数组的元素个数

#ifdef __COUNT_BIT__
/**
 * @brief 计算二进制中1的个数，效率最高
 *
 * @param n
 * @return int
 */
int bitCount1(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n &= (n - 1);
    }
    return count;
}

int bitCount2(int n)
{
    int count = 0;
    unsigned int m = n;
    while (m)
    {
        if (m % 2 == 1)
        {
            count++;
        }
        m /= 2;
    }
    return count;
}

int countZeroBits(int num)
{
    int count = 0;
    while (num + 1)
    {
        count++;
        num |= (num + 1);
    }
    return count;
}

int main(int argc, char **argv)
{

    int a, b, c = 21;
    a = countZeroBits(c);
    //b = bitCount2(c);
    printf("a = %d", a);
    return 0;
}
#endif

#ifdef __EVER_TEST__
// register 变量,会提高运行的效率
int registerTest(void)
{
    register int temp, i;
    // int temp, i;
    time_t start, end;
    time(&start); // 获取当前时间
    for (i = 0; i < 30000000; i++)
    {
        for (temp = 0; temp < 100; temp++)
            ;
    }
    printf("ok\n");
    time(&end);
    printf("%d\n", (unsigned int)(end - start));
}

/**
 * @brief 交换两个变量的数值，顺便测试一下assert报错可不可以识别出来
 *
 * @param p1
 * @param p2
 * @return int
 */
int mySwag(int *p1, int *p2)
{
    assert(*p1 > 4);
    assert(*p2 < 6);

    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(int argc, char **argv)
{
    int a = 5, b = 7;
    mySwag(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    // registerTest();
    /*  测试计算数组元素个数的宏是否正确
        int num = 0;
        int a[5] = { 0, 1, 2, 3};
        num = NUMBER(a);
        printf("num: %d\n", num); */
    return 0;
}

#endif // __EVER_TEST__

/*
int main(int argc, char* argv[])
{
    char *p;
    const unsigned k = 1024*1024*1024*1.2;
    printf("%x\n", k);
    p = (char *)malloc(k);
    if (p != NULL)
    {
        printf("OK!!\n");
    }
    else
    {
        printf("FAIL!!\n");
    }
    return 0;
}
  */

#ifdef __PRINT_1_1000_

#define L I, I, I, I, I, I, I, I, I, I
#define I printf("%3d", i++)
// #define N printf("n")

#define A(x) \
    x;       \
    x;       \
    x;       \
    x;       \
    x;       \
    x;       \
    x;       \
    x;       \
    x;       \
    x;

int main()
{
    int i = 1;
    // L;

    A(A(A(printf("%d ", i++))));

    return 0;
}

#endif // 0
