#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#define NDEBUG
#include <assert.h>

/**
 * @brief 字符串转换为整数
 * 
 * @param str 
 * @return int 
 */
int strToInt(const char* str)
{
    int num = 0;
/*   应该无符号位，做减号  
    if (*str == '-')
    {
        sign = -1;
        str++;
    } */
    while (*str != '\0') 
    {
        int digital = *str - '\0';
        num = num*10 + digital;
        str++;
    }
    return num;
}

int main(int argc, char** argv)
{
    char str[] = "-";
    int num = 0;
    num = strToInt(str);
    printf("%d", num);
    return 0;
}




