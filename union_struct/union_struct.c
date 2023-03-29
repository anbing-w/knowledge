#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define VAROFFSET(type, mem) ((unsigned long)(&((type *)0)->mem))

typedef struct tab_student
{
    char name[32];
    int age;
    char *maxim;
} T_STUDENT;

int main(int argc, char **argv)
{
    int size = 0;
    T_STUDENT student;
    size = sizeof(student);
    student.age = 15;
    char *ptr = student.age;
    T_STUDENT* Pstu = (T_STUDENT*)((char*)ptr -((unsigned long)(&((T_STUDENT*)0)->age)));



    printf("the size of struct student is %d\n", size);
    printf("the size of struct student is %p\n", Pstu);
    return 0;
}


