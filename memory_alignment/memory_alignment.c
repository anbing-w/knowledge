#include <stdio.h>

// #define _UNION_TARGET

#ifdef __STRUCT__
// 练习1
struct S1
{
    char c1;
    int i;
    char c2;
};

// 练习2
struct S2
{
    char c1;
    char c2;
    int i;
};

// 练习3
struct S3
{
    double d;
    char c;
    int i;
};

// 结构体总大小是最大对齐数(每个成员变量都有一个对齐数)的整数倍，下面是double，(结构体内成员变量不会和嵌套结构体的成员变量内存对齐)
struct S4
{
    char c1;
    struct S3 s3;
    double d;
};

struct S5
{
    char c;
    int i;
    double d;
};

struct S6
{
    char c1;
    struct S5 s3;
    double d;
};
struct S7
{
    char c1;
    char c2;
    int i;
    double d1;
    double d2;
};

int main()
{
    printf("%d\n", sizeof(struct S1)); // 12=1+3+4+1+3
    printf("%d\n", sizeof(struct S2)); // 8=1+1+2+4
    printf("%d\n", sizeof(struct S3)); // 16=8+1+4+3
    printf("%d\n", sizeof(struct S4)); // 32 = 1+7+16+8
    printf("%d\n", sizeof(struct S5)); // 16 = 1+3+4+8
    printf("%d\n", sizeof(struct S6)); // 32 = 1+7+16+8
    printf("%d\n", sizeof(struct S7)); // 24 = 1+7+16+8

    return 0;
}

#elif __bit_segment

struct S
{
    char a : 3;
    char b : 4;
    char c : 5;
    char d : 4;
};

int main()
{
    struct S s = {0};
    s.a = 10;
    s.b = 12;
    s.c = 3;
    s.d = 4;

    printf("%d %d %d %d\n", s.a, s.b, s.c, s.d);
    printf("%d\n", sizeof(struct S)); // 3
    return 0;
}

#elif __UNION__
// 联合类型的声明
union Un
{
    char c;
    int i;
};

// 联合变量的定义
union Un un;

union data
{
    int a;
    char b;
    double c;
};

int main()
{
    printf("%d\n", sizeof(un));         // 4 = 1 + 3
    printf("%d\n", sizeof(union data)); // 8 = 4 + 1 +3
    un.i = 0x11223344;
    un.c = 0x55;
    printf("%x\n", un.i); // 11223355（小端存储）
    printf("%x\n", un.c); // 55
    return 0;
}
#elif __TYPEDEF__TYPE

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;



//2+4+2 + 8(下面结构体的最大字节数是8，就跟普通的结构体是一样的，换汤不换药)
typedef struct st_task
{
    uint16_t id;
    uint32_t value;
    uint64_t timestamp;
} st_task;

int main(void)
{
    st_task task = { 0 };
    //memcpy(&task, 0, sizeof(task));
    uint64_t a = 0x00010001;
    memcpy(&task, &a, sizeof(uint64_t));
    printf("%d\n", sizeof(task));
    printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
    return 0;
}
#else

typedef struct p
{
    int a;
    char b;
    short c;
 
}__attribute__((aligned(4))) pp;
 
typedef struct m
{
    char a;
    int b;
    short c;
}__attribute__((aligned(4))) mm;
 
typedef struct o
{
    int a;
    char b;
    short c;
}oo;
 
typedef struct x
{
    int a;
    char b;
    struct p px;
    short c;
}__attribute__((aligned(8))) xx;
 
int main()
{           
    printf("sizeof(int)=%d,sizeof(short)=%d.sizeof(char)=%d\n",sizeof(int) \
                                                ,sizeof(short),sizeof(char));
    printf("pp=%d,mm=%d \n", sizeof(pp),sizeof(mm));
    printf("oo=%d,xx=%d \n", sizeof(oo),sizeof(xx));
    return 0;
}

#endif
