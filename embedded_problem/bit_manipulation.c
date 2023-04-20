#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BIT3 (0x1 << 3)

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

