#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#if 0
int main()
{
    int x[] = {10, 20, 30};
    int *px = x;
    printf("%#p\n", &px);
    printf("%d\n", ++*px); // ���ȼ���ͬ������������ȡֵ10������������11
    printf("%d\n", *px);
    px = x; // ÿ�ν�ָ��ָ����׵�ַ����
    printf("%#p\n", &px);
    printf("%d\n", (*px)++); // ȡֵ11��������������Ҳ࣬���ֵ���䣬ʵ��ֵ+1
    printf("%d\n", *px);
    px = x;
    printf("%#p\n", &px);
    printf("%d\n", *px++); //*px++ == *(px++)�����ȼ���ͬ����������,�൱��*x, x=px++,����������������Ҳ࣬����x����px*,*x==*px==12����ʵ�������ڵ�px�Ѿ���������һ����λ���׵�ַ�ı�
    printf("%d\n", *px);   // ���Դ�ʱ��*px���Ǻ�һ����λ��ֵ
    px = x;
    printf("%#p\n", &px);
    printf("%d\n", *(px++)); // ��������������������Ҳ࣬�����ڴ˲����֣���ʵ���Ѿ�������һ����λ���׵�ַ�ı�
    printf("%d\n", *px);     // ʵ������һ����λ
    px = x;
    printf("%#p\n", &px);
    printf("%d\n", *++px); // �������������������������Ч������
    printf("%d\n", *px);
    return 0;
}
#endif

/***
 * �жϷ���ֵ
int fun(int *p)
{
    return p[6];
}

void main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b;
    b = fun(&a[2]);
    printf("%d\n", b);
}
 */
/**
 * �ֲ�������������ֻ�ڸñ������ڵľֲ���Χ
 */
#if 0
char *GetMemory(void) // line 1
{
    char *p = (char *)malloc(10); // line 2
    return p;                     // line 3
}

void main(void)
{
    char *str = NULL;           // line 3
    str = GetMemory();          // line 4
    strcpy(str, "hello world"); // line 5
    printf("%s",str);                // line 6
}
#endif

#if 0
//�ж��Ƿ�Ϊ��ָ�룬��ֹ�����ô���NULL�Ļ�һ��ָ���ַΪ0�����ַ�㸳ֵ���ܻ����Ī������Ĵ���
static int data[100];
void fun(int i , int *value)
{
    assert(value);
    data[i] = *value;
    *value = 0;
}
#endif
