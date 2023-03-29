#include <stdio.h>


/**
 * @brief constructor --���캯����destructor--��������
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




