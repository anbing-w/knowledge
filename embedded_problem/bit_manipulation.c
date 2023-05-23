#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BIT3 (0x1 << 3)

// uint32 奇偶位数字互换
#define SWAG(BIT) (BIT = ((BIT & 0x55555555) << 1) | ((BIT & 0xaaaaaaaa) >> 1))

#define SWAP_BIT(n) (n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1))

//不使用~取反uint32
#define REVERSED(x)  (x=(x^0xffffffff))


#define SetBit(x, y)   (x |= (1<<y))      // 特定位置1,x为目标,y为第几位
#define ClearBit(x, y) (x &= ~(1<<y))   // 特定位清0
#define GetBit(x, y)   (x &= (1<<y))      // 特定位取值
#define ReveBit(x, y)  (x ^= (1<<y))     // 特定位取反





int main()
{
    unsigned int i = 5;
    // int j = SWAG(i);
    //int j = (i & 0x55555555 << 1) + (i & 0xaaaaaaaa >> 1);

   // SWAP_BIT(i);
   //SWAG(i);
    REVERSED(i);
    //printf("%d\n", j);
    printf("%d\n", i);
    return 0;
}

#if 0
static int a;

void set_bit(void)
{
    a |= BIT3;
}

void clear_bit(void)
{
    a &= ~BIT3;  
}

typedef struct TEST
{
    double t;
    char b;
    int a;
    short c;
}TEST;
typedef union{
    long long i;//long是4个字节
    int k[5];
    //char c;
}TEST_LIST;
typedef union{
    int i;
   // int k[5];
    char arr[5];
}TEST_LIST2;

int main(int argc, char** argv){
    TEST t;
    TEST_LIST b;
    int len;
    len = sizeof(1+2.0);
    char c = 'a';
    char a[] = "hello world";
    printf("%ld\n", sizeof(c));
    printf("%ld\n", sizeof('a'));
    printf("%ld\n", sizeof(a));
    printf("%ld\n", strlen(a));
    printf("%ld\n", strlen("\n\t\tagAAtang"));
    printf("%ld\n", len);
    printf("%ld\n", sizeof(t));
    printf("%ld\n", sizeof(TEST_LIST));
    printf("%ld\n", sizeof(TEST_LIST2));
    return 0;
}
#endif




