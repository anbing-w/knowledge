#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define __GET_MEMORY_

#ifdef __GET_MEMORY_

#endif // __GET_MEMORY_
/**
 * @brief Get the Memory1 object 函数参数是值传递，对形参的改变不影响实参
 *调用GetMemory(str)时，函数将str作为实参出传入类型（char *）类型的p中，此时p只是str的临时拷贝，p的地址并不是并不是真正str的地址，所以当函数调用时，
 *str无法通过临时拷贝的p获得malloc分配的100个动态分配的内存,始终都是NULL，所以strcpy无法进行拷贝字符串。
 * @param p
 */
void getMemory1(char *p)
{
    p = (char *)malloc(100);
}

void test1(void)
{
    char *str = NULL;
    getMemory1(str);
    // str = (char *)malloc(100);
    strcpy(str, "hello");
    printf(str);
    // printf("%s\n", str);
}
/****************************************修改*********************************************
void getMemory1(char** p) {
    if (*p != NULL) {
        free(*p);
        }
    *p = (char*)malloc(100);
}
void test1(void) {
    char* str = NULL;
    getMemory1(&str);
    strcpy(str, "hello");
    printf("%s", str);
    free(str);
    str = NULL;
}
******************************************************************************************/

/**
 * @brief Get the Memory2 objectp 是一个局部变量，其作用域仅限于 getMemory2 函数内部。
 *        在函数返回后，p 将被销毁，其指向的内存空间也将无法访问。
 *        因此，在 test2 函数中，指针变量 str 指向了一段无法访问的内存空间
 * @return void*
 */
/* char *GetMemory2(void)
{
    char p[] = "hello world";//加上static ，内存就会从栈区放到全局区，增加变量的寿命
    return p;
}

void Test(void)
{
    char *str = NULL;
    str = GetMemory();
    printf(str);
}
 */

/****************************************修改*********************************************
char* getMemory2(void) {
    char* p = (char*)malloc(6);
    strcpy(p, "hello");
    return p;
}

void test2(void) {
    char* str = NULL;
    str = getMemory2();
    printf("%s", str);
    free(str);
}
******************************************************************************************/

/*
出现问题：内存泄漏
分析原因：在堆区（Heap）中malloc()会动态分配内存，用完要free,否则造成内存泄漏。
*/
void GetMemory3(char **p, int num)
{
    *p = (char *)malloc(num);
}

void Test3(void)
{
    char *str = NULL;
    GetMemory(&str, 100);
    strcpy(str, "hello");
    printf(str);
}

void Test4(void)
{
    char *str = (char *)malloc(100);
    strcpy(str, "hello");
    free(str);  // 悬空指针
    str = NULL; // str指向NULL，避免悬空指针出现
    if (str != NULL)
    {
        strcpy(str, "world");
        printf(str);
    }
}

/*
虽然都是局部变量，但题目五用函数返回值来传递动态内存的地址；而题目二return语句返回指向“栈”内存的指针，
因为该内存在函数结束时自动消亡。同样，动态分配的内存并不会自动释放，容易有内存泄漏的风险。
*/
char *getMemory(void)
{
    char p[] = "hello world";
    return p;
}

char *getMemory(int num)
{
    char *p = (char *)malloc(num);
    return p;
}

// 运行正确，但有内存泄漏
void getMemory(char **p, int num)
{
    *p = (char *)malloc(num);
}

/*
因为getMemory(void)内的“hello world”是常量字符串，位于静态存储区，它在程序生命期内恒定不变。
无论什么时候调用getMemory(void)，它返回的始终是同一个“只读”的内存块。
p[0] = 'n'; 程序就会中断，并且提示内存错误
*/
char *getMemory(void)
{
    char *p = "hello world";
    return p;
}

void Test(void)
{
    char *str = NULL;
    str = getMemory();
    printf(str);
}

int main()
{
    test2();

    return 0;
}

#ifdef __FUNCTION_PARAM

/**
 * @brief 压入栈的地址是从高到底，函数的参数入栈顺序是从右到左
 *
 * @param a
 * @param b
 * @param c
 */
void stackPushTest(int a, int b, int c)
{
    printf("a:%#p\n", (unsigned int)&a);
    printf("b:%#p\n", (unsigned int)&b);
    printf("c:%#p\n", (unsigned int)&c);
}

int main(int argc, char **argv)
{
    char *ptr;
    if ((ptr = (char *)malloc(-1)) == NULL)
    {
        puts("GOT a null pointer\n");
    }
    else
    {
        puts("GOT a valid pointer\n");
    }
}
#endif // __FUNCTION_PARAM
