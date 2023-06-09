#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define __TWO_DIMENSIONAL_ARRAY_

#ifdef __ARRAY_SORT__

int values[] = {40, 10, 100, 90, 20, 25};

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    int len = sizeof(values) / sizeof(values[0]);
    qsort(values, len, sizeof(int), compare);
    for (n = 0; n < len; n++)
        printf("%d ", values[n]);
    return 0;
}

#endif // __ARRAY_SORT__

#ifdef __STRUCT_SORT__

// void qsort(void* base, size_t num, size_t size, int(*compare)(const void*, const void*))

typedef struct
{
    char name[30]; // 学生姓名
    int Chinese;   // 语文成绩
    int Math;      // 数学成绩
    int English;   // 英语成绩
} st;
int cmp(const void *a, const void *b)
{
    st *pa = (st *)a;
    st *pb = (st *)b;
    int num1 = pa->Chinese + pa->English + pa->Math;
    int num2 = pb->Chinese + pb->English + pb->Math;

    return ((int)num1 - (int)num2); //  从小到大
}
int main(void)
{
    st students[7] = {
        {"zhou ", 97, 68, 45},
        {"wu   ", 100, 32, 88},
        {"zheng", 78, 88, 78},
        {"wang ", 87, 90, 89},
        {"zhao ", 87, 77, 66},
        {"qian ", 59, 68, 98},
        {"sun  ", 62, 73, 89}};
    qsort(students, 7, sizeof(st), cmp); // 注意区别 students 与 st

    for (int i = 0; i < 7; i++)
    {
        printf("%s%4d%4d%4d\t", students[i].name, students[i].Chinese, students[i].Math, students[i].English);
        printf("sum:%d\n", students[i].Chinese + students[i].English + students[i].Math);
    }

    system("pause");
    return 0;
}

#endif // __STRUCT

#ifdef __POINTER__SORT__
int compare(const void *arg1, const void *arg2);

int main(int argc, char **argv)
{
    int i;

    char *arr[5] = {"i", "love", "c", "programming", "language"};

    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(char *), compare);

    for (i = 0; i < 5; i++)
    {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int compare(const void *arg1, const void *arg2)
{
    char *a = *(char **)arg1;
    char *b = *(char **)arg2;
    int result = strcmp(a, b);
    if (result > 0)
    {
        return 1;
    }
    else if (result < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

#endif // __POINTERSORT

#ifdef __TWO_DIMENSIONAL_ARRAY_

int compare(const void *arg1, const void *arg2);

int main(int argc, char **argv)
{
    int i;

    char arr[5][16] = {"i", "love", "c", "programming", "language"};

    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), compare);
    printf("%s\n", arr[0]);
    for (i = 0; i < 5; i++)
    {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int compare(const void *arg1, const void *arg2)
{
    char *a = (char *)arg1;
    char *b = (char *)arg2;
    int result = strcmp(a, b);
    if (result > 0)
    {
        return 1;
    }
    else if (result < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

#endif // __TWO_DDIM
