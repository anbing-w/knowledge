#include <stdio.h>


/**
 * @brief constructor --构造函数；destructor--析构函数
 * 
 */

__attribute((constructor)) void before_main()
{
    printf("%s\n", __FUNCTION__);
}

__attribute((destructor)) void after_main()
{
    printf("%s\n", __FUNCTION__);
}


int main()
{
    printf("%s\n", __FUNCTION__);
    return 0;
}




