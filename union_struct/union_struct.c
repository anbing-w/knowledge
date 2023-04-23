#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>


//计算结构体的首地址
#define VAROFFSET(type, mem) ((unsigned long)(&((type *)0)->mem)) // 结构体成员相对于首地址偏移量

////#define GET_STRUCT_ENTRY(ptr, type, mem)  ((type *)((char *)ptr - VAROFFSET(type, mem)))  //获得结构体的地址

#define GET_STRUCT_ACCESS(ptr, type, mem) ((type *)((char *)ptr - VAROFFSET(type, mem)))

typedef struct tab_student
{
    char name[32];
    int age;
    char *maxim;
} T_STUDENT;

union u3
{
    char c[4];
    int i;
}U4;


typedef union
{
    uint8_t Value;
    uint8_t Byte;
/*     struct 
    {
        unsigned BIT0:1;
        unsigned BIT1:1;
        unsigned BIT2:1;
        unsigned BIT3:1;
        unsigned BIT4:1;
        unsigned BIT5:1;
        unsigned BIT6:1;
        unsigned BIT7:1;
    }Bits; */
}byte_t;


    struct 
    {
        unsigned BIT0:1;
        unsigned BIT1:1;
        unsigned BIT2:1;
        unsigned BIT3:1;
        unsigned BIT4:1;
        unsigned BIT5:1;
        unsigned BIT6:1;
        unsigned BIT7:1;
    }Bits;

int main(int argc, char **argv)
{
    //测试结构体成员地址和推算结构体的地址
/*  int size1 = 0;
    int size2 = 0;
    T_STUDENT student;
    T_STUDENT a[2];
    size1 = sizeof(student);
    size2 = sizeof(a);
    student.age = 15;
    int *ptr1 = &student.age;
    int *ptr2 = &(((T_STUDENT *)0)->age);
    T_STUDENT *ptr3 = &student;
    T_STUDENT *Pstu = (T_STUDENT *)((char *)ptr1 - ((unsigned long)(&((T_STUDENT *)0)->age)));

    printf("the size of struct student is %d\n", size1);
    printf("the size of struct student is %d\n", size2);
    printf("the size of struct student is %#p\n", ptr1);
    printf("the size of struct student is %#p\n", ptr2);
    printf("the size of struct student is %#p\n", ptr3);
    printf("the size of struct student is %#p\n", Pstu);
    return 0; */
    //byte_t byte_count;
    printf("the size of byte_count is %d\n",sizeof(byte_t));
    printf("the size of byte_count is %d\n",sizeof(Bits));

    U4.c[0] = 0x04;
    printf("%#p\n",&U4.c[0]);
    U4.c[1] = 0x03;
    printf("%#p\n",&U4.c[1]);
    U4.c[2] = 0x02;
    printf("%#p\n",&U4.c[2]);
    U4.c[3] = 0x01;
    printf("%#p\n",&U4.c[3]);
    printf("%x\n",U4.i);
    return 0;
}


