#include<stdio.h>

#if 0
#ifdef POINTER_FIND
//指针法判断大小端
int check_sys(){
    int a = 1;
    char* p = (char*)&a;

    if(*p == 1){ // 表示大端
        return 1;
    }
    else{ //表示小端
        return 0;
    }
}
#else 
    typedef union u
    {           
        int i;
        char c;
    }u;

    int check_sys(){
        u check;
        check.i = 1;
        return check.c;
    }
#endif


int main(){
    if(check_sys() ==1){
        printf("小端\n");
    }
    else{ 
        printf("大端\n");
    }
}                               
#endif

int main(){
    int a = 1,result;
    result = ((a & 0x000000ff) << 24) | \
             ((a & 0x0000ff00) << 8) | \
             ((a & 0x00ff0000) >> 8) | \
             ((a & 0x000000ff) >> 24);
    printf("result = %d\n",result);
    return 0;
}



