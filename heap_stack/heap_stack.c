#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
int global_noinit_var;
int global_init_var = 1;
static int static_global_NoInit_var;
static int static_global_init_var = 1;
const int const_static_global_noinit_var; //�������β���ʼ��ֵĬ��Ϊ0
const int const_static_global_init_var = 1;

int main(int argc, char **argv)
{
    static int static_NoInit_var;
    static int static_init_var = 1; 
    int *heap_var = (int *)malloc(4);
    int *heap_var2 = (int *)malloc(4);
    int var[16];
    int var2[16];
    int var3[16];
    char *p = "Hello world";
    printf("ȫ�ֳ�����������ַ��\n");    
    printf("const_static_global_noinit_var address = 0x%p\n", &const_static_global_noinit_var);
    printf("const_static_global_init_var   address = 0x%p\n", &const_static_global_init_var);
    printf("��ͬ�ط�����ͬ�ַ�����ַ��ͬ��\n");
    printf("string                         address = 0x%p\n", "Hello world");
    printf("char *p = string               address = 0x%p\n", p);
    printf("ȫ�ֺ;�̬��ʼ��������ַ��\n");
    printf("global_init_var                address = 0x%p\n", &global_init_var);
    printf("static_global_init_var         address = 0x%p\n", &static_global_init_var);
    printf("static_init_var                address = 0x%p\n", &static_init_var);
    printf("ȫ�ֺ;�̬δ��ʼ��������ַ��\n");
    printf("global_noinit_var              address = 0x%p\n", &global_noinit_var);
    printf("static_global_NoInit_var       address = 0x%p\n", &static_global_NoInit_var);
    printf("static_NoInit_var              address = 0x%p\n", &static_NoInit_var);
    printf("������ַ��\n");
    printf("heap_var                       address = 0x%p\n", heap_var);
    printf("heap_var2                      address = 0x%p\n", heap_var2);
    printf("�����ڲ��ֲ�������ַ�ɸߵ���������\n");
    printf("var                            address = 0x%p\n", var);
    printf("var2                           address = 0x%p\n", var2);
    printf("var3                           address = 0x%p\n", var3);
    printf("var[1]                         address = 0x%p\n", &var[1]);
    printf("var[2]                         address = 0x%p\n", &var[2]);

    return 0;
}




