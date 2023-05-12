#include <string.h>
#include <stdio.h>
#include <assert.h>

#define __REWRITE__MYTEST__

#ifdef __REWRITE_STRCMP__
/**
 * @brief strcmp 函数复现
 *
 * @return int
 */
// int my_strcmp(const char *s1, const char *s2)
// {
//     while (*s1 == *s2) { //一个字符一个字符的比较，直到不相等
//         if (s1 == '\0')
//         {
//             return 0;
//             s1++;
//             s2++;
//         }
//         return *s1 - *s2;
//     }

// }

int my_strcmp(const char *str1, const char *str2)
{
    assert(NULL != str1);
    assert(NULL != str2);
    while (*(unsigned char *)str1 == *(unsigned char *)str2)
    {
        if (*(unsigned char *)str1 == '\0') // 要写成==‘0’，否则不对，切记
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int main()
{
    char str1[] = "SaaORRY";
    char str2[] = "SORRY";
    // 经过手算可发现I的ACSII=73，S的ACSII=83,应该返回-10
    printf("%d\n", My_strcmp(str1, str2));
    printf("%d\n", strcmp(str1, str2));
    return 0;
}
#endif
#ifdef __REWRITE__STRSTR__

/* char *my_strstr(const char *str1, const char *str2)
{ // const char *str防止str被修改
    assert(str1 != NULL);
    assert(str2 != NULL);
    char *p1 = NULL; // 创建三个指针，一个指向str2，两个指向str1
    char *p2 = NULL;
    char *pc = str1;

    while (*pc)
    {
        p1 = pc; // pc的内容给p1
        p2 = str2;
        while (*p1 = '\0' && *p2 == *p1)
        { // 如果不相等，或者str2已经到了\0.或者str1不够长，则不进去
            {
                p2++;
                p1++;
            }
            if (*p2 == '\0')
            {
                return pc;
            }
            else
            {
                pc++;
            }
        }
        return NULL;
    }
} */

char *my_strstr(const char *str1, const char *str2)
{
    assert(str1 && str2);
    const char *s1 = str1;
    const char *s2 = str2;
    const char *cur = str1;

    // 如果子串一开始就是空，那么直接返回母串
    if (*str2 == '\0')
    {
        return str1;
    }

    while (*cur != '\0')
    {
        s1 = cur;
        s2 = str2;
        while ((*s1 == *s2) && *s1 && *s2) // s1和s2不能走到\0
        {
            s1++;
            s2++;
        }

        if (*s2 == '\0')
        {
            return cur;
        }
        cur++;
    }

    return NULL;
}

int main(void)
{
    char p[] = "galodajdisa";
    char q[] = "ajd";
    char *r = my_strstr(p, q);
    printf("r:%s\n", r);

    if (r)
    {
        printf("%d\n", (r - p + 1));
    }
    else
    {
        return 0;
    }

    // getchar();
    return 0;
}
#endif
#ifdef __REWRITE__STRCPY__

char *my_strcpy(char *dest, const char *src)
{
    assert(dest != NULL);
    assert(src != NULL);
    char *ptr = dest;

    // 加下下面的判断的话，使用memset后就会返回
    //  if (strlen(dest) < strlen(src))
    //  {
    //      return 0;
    //  }
    while (*src)
    {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}
// 模拟strncpy,strncpy返回的是目标空间的起始地址
char *my_strncpy(char *dest, const char *src, int n)
{
    assert(dest && src);
    char *ptr = dest; // 存储起始地址
    size_t i = 0;     // 记录复制字符串的个数

    while (*src != '\0' && i < n)
    {
        *ptr++ = *src++;
        i++;
    }
    while (i < n)
    {
        *ptr++ = '\0';
        i++;
    }
    return dest;
}

int main()
{
    char src[] = "Hello World!";
    char dest[20];

    // test case 1: copy entire string
    my_strncpy(dest, src, strlen(src) + 1);
    printf("dest after copy entire string: %s\n", dest);

    // test case 2: copy part of string
    memset(dest, 0, strlen(dest));
    my_strncpy(dest, "AHHSUHSUIAH", 5);
    printf("dest after copy part of string: %s\n", dest);

    // test case 3: copy more than the string length
    my_strncpy(dest, src, 20);
    printf("dest after copy more than string length: %s\n", dest);

    // test case 4: copy empty string
    my_strncpy(dest, "", 5);
    printf("dest after copy empty string: %s\n", dest);

    return 0;
}
#endif

#ifdef __REWRITE__MEMCPY__

void *my_memcpy(void *dest, const void *src, size_t n)
{
    assert(dest != NULL);
    assert(src != NULL);
    char *pdest = (char *)dest;
    const char *psrc = (const char *)src;
    while (n--)
    {
        *pdest++ = *psrc++;
    }
    return dest;
}

void *my_memmove(void *dest, void *src, size_t n)
{
    // assert(dest != NULL);
    // assert(src != NULL);
    char *pdest = (char *)dest;
    char *psrc = (char *)src;
    if ((psrc <= pdest) && ((psrc + n) >= pdest))
    { // source and destination memory regions overlap
        psrc += n - 1;
        pdest += n - 1;
        while (n--)
        {
            *pdest-- = *psrc--;
        }
    }
    else
    { // nomal copy
        while (n--)
        {
            *pdest++ = *psrc++;
        }
    }
    return dest;
}

int main()
{
    // test case 1: normal copy
    char src1[] = "hello world";
    char dest1[12] = "0";
    my_memmove(dest1, src1, strlen(src1) + 1);
    // assert(strcmp(dest1, "hello world") == 0);
    printf("dest1: %s\n", dest1);
    // test case 2: overlapping memory regions
    char src2[] = "123456789";
    // memset()
    my_memmove(src2 + 1, src2, 7);
    printf("src2: %s\n", src2);
    // assert(strcmp(src2, "121234567") == 0);

    // test case 3: null pointers
    // char* src3 = NULL;
    // char* dest3 = NULL;
    // //assert(memmove(dest3, src3, 10) == NULL);
    // my_memmove(dest3, src3, 10);
    // printf("dest3: %s\n", dest3);
    // printf("All tests pass!\n");
    return 0;
}
#endif

#ifdef __REWRITE__STRCAT__
char *my_strcat(char *dest, const char *src)
{
    assert(dest != NULL);
    assert(src != NULL);
    char *pdest = dest;
    const char *psrc = src;
    while (*pdest)
    {
        pdest++;
    }
    while (*psrc)
    {
        *pdest++ = *psrc++;
    }
    pdest = '\0';
    return dest;
}
char *my_strncat(char *dest, const char *src, size_t n)
{
    assert(dest != NULL);
    assert(src != NULL);
    char *pdest = dest;
    const char *psrc = src;
    /*  while (n >= strlen(psrc))
        {
            n = strlen(psrc);
        } */
    while (*pdest)
    {
        pdest++;
    }
    while (n-- && *psrc)
    {
        *pdest++ = *psrc++;
    }
    *pdest = '\0';
    return dest;
}

int main()
{
    char src[] = " world";
    char dest[20] = "hello";
    // my_strcat(dest, src);
    printf("%s\n", dest);

    // memset(dest+5, 0, sizeof(dest));
    my_strncat(dest, src, 3);
    printf("%s\n", dest);
    return 0;
}
#endif

#ifdef __REWRITE_STRLEN__

// 创建临时变量
size_t my_strlen1(const char *src)
{
    assert(src != NULL);
    int len = 0;
    while (*src++)
    {
        //*src++;
        len++;
    }
    return len;
}

// 不创建临时变量，使用递归进行计数

size_t my_strlen2(const char *src)
{
    assert(src != NULL);
    int len = 0;
    if (*src++)
    {
        return my_strlen1(src) + 1;
    }
    else
    {
        return 0;
    }
}

size_t my_strlen3(const char *src)
{
    assert(src != NULL);
    const char *start = src;
    const char *end = src;
    while (*end)
    {
        end++;
    }
    return end - start;
}

int main(int argc, char **argv)
{
    char a[] = "helloh world!";
    int len;
    len = my_strlen3(a);
    // len = strlen(a);
    printf("%d\n", len);
    return 0;
}

#endif

#ifdef __REWRITE__MYTEST__
char *my_strcpy(char *dest, const char *src)
{
    assert(dest != NULL);
    assert(src != NULL);

    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest;
}

char *my_strcat(char *dest, const char *src)
{
    assert(dest != NULL);
    assert(src != NULL);
    while (*dest != '\0')
    {
        *dest++;
    }
    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest;
}
int my_strcmp(const char *s1, const char *s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*s1 && *s2 && *s1 == *s2)
    {
        *s1++;
        *s2++;
    }
    if (*s1 == '\0' && *s2 == '\0')
    {
        return 0;
    }
    else
    {
        // printf("%d\n", (*s1 - *s2));
        /*************************************************************************
         *              为什么返回值是1而不是-1，
         *         三目运算符首先计算的是expression1，非零值即为真，与符号无关
                printf("%d\n", ((2 - 3)?1:-1));
        **************************************************************************/
        return (*s1 < *s2) ? 1 : -1;
    }
    // return *s1 - *s2;
}

int my_strlen(const char *src)
{
    assert(src != NULL);
    int count = 0;
    while (*src++)
    {
        count++;
    }
    return count;
}

char *my_strstr(const char *str1, const char *str2)
{
    //assert(str1 && str2);
    if (str1 == NULL || str2 == NULL)
    {
        return NULL;
    }
    const char *s1 = NULL;
    const char *s2 = NULL;
    const char *cur = str1;

    // 如果子串一开始就是空，那么直接返回母串
    if (*str2 == '\0')
    {
        return (char *)str1;
        // return str1;
    }
    while (*cur != '\0')
    {
        s1 = cur;
        s2 = str2;
        while ((*s1 == *s2) && *s1 && *s2) // s1和s2不能走到\0
        {
            s1++;
            s2++;
        }
        if (*s2 == '\0')
        {
            return (char *)cur;
            // return cur;
        }
        cur++;
    }
    return NULL;
}

char *my_strstr2(const char *str1, const char *str2)
{
    if (str1 == NULL || str2 == NULL)
    {
        return NULL;
    }
    const char *s1 = NULL, *s2 = NULL, *cur = str1;
    if (*str2 == '\0')
    {
        return (char *)str1;
    }
    while (*cur != '\0')
    {
        s1 = cur;
        s2 = str2;
        while (*s1 == *s2 && *s1 != '\0'&& *s2 != '\0')
        {
            s1++;
            s2++;
        }
        if (*s2 == '\0')
        {
            return (char *)cur;
        }
        cur++;
    }
    return NULL;
}

int main(int argc, char **argv)
{
    // Test case 1: Empty string
    const char s1[] = "abcdefghijklmnopqrstuvwxyzABCDEF";
    const char s2[] = "bc";
    printf("Test case 1: %s\n", my_strstr2(s1, s2)); // expected output: 0
    return 0;
}

#endif // __REWRITE__MYTEST__
