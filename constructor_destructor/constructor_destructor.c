#include <stdio.h>



// void before() __attribute__((constructor));
// void after() __attribute__((destructor));


/**
 * @brief attribute可以设置，变量属性，函数属性和类型属性
 * 
 */

__attribute__((constructor)) void before_main()
{
    printf("%s\n", __FUNCTION__);
}

__attribute__((destructor)) void after_main()
{
    printf("%s\n", __FUNCTION__);
}



int main()
{
    printf("%s\n", __FUNCTION__);
    return 0;
}




