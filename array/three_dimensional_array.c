#include "stdio.h"
#include <string.h>

#if 0
void main(){
	//三维数组
	int a[2][3][4] =
	{
		{
			{6,2,3,4},
			{5,11,15,8},
			{8,20,10,11}
		},
		{
			{0,0,3,4},
			{5,0,7,8},
			{8,1,18,31}
		}
	};
	int i, j, k;
	int(*p)[3][4];					//p是指向二维数组的指针 
	p = a;							//p指向三维数组的0行 (也即p指向一个二维数组) 
	//p=&a[0];						//与上等价
	printf("				【三维数组的遍历】：\n\n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 4; k++) {
//元素值遍历 ： 
				printf("a[%d][%d][%d]=%-9d  ", i, j, k, *(*(*(p + i) + j) + k));//元素值 
				printf("a[%d][%d][%d]=%-9d  ", i, j, k, *(*(a[i] + j) + k));	//元素值 
				printf("a[%d][%d][%d]=%-9d  ", i, j, k, *(a[i][j] + k));		//元素值 
				printf("a[%d][%d][%d]=%-9d  ", i, j, k, *(&a[i][j][k]));		//元素值 
				printf("a[%d][%d][%d]=%-9d  ", i, j, k, a[i][j][k]);			//元素值 
				printf("a[%d][%d][%d]=%-9d\n", i, j, k, p[i][j][k]);			//元素值 
				
//元素地址遍历： 
//				printf("&a[%d][%d][%d]=%-9d  ", i, j, k, *(*(p + i) + j) + k);	//元素地址 
//				printf("&a[%d][%d][%d]=%-9d  ", i, j, k, *(a[i] + j) + k);		//元素地址
//				printf("&a[%d][%d][%d]=%-9d  ", i, j, k, a[i][j] + k);			//元素地址
//				printf("&a[%d][%d][%d]=%-9d\n", i, j, k, &a[i][j][k]);			//元素地址

//由于少了整体括号，所以出现错误的遍历，只有a[0][0][0],a[0][1][0],a[0][2][0],a[1][0][0],a[1][1][0],a[1][2][0]正确
//
//				printf("a[%d][%d][%d]=%-9d  ", i, j, k, **(*(p + i) + j) + k);	//错误，由于最外层少括号 
//				printf("a[%d][%d][%d]=%-9d  ", i, j, k, **(a[i] + j) + k);		//错误，由于最外层少括号 
//				printf("a[%d][%d][%d]=%-9d  ", i, j, k, *a[i][j] + k);			//错误，由于最外层少括号 
//				printf("a[%d][%d][%d]=%-9d\n", i, j, k, *&a[i][j][k]);			//正确 
			}
			printf("\n");
		}
	}
}
#endif

#if 0
int main(int argc, char **argv)
{
	int a[3][4][5]; // 声明一个3x4x5的数组

	// 使用循环来为数组分配值
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				a[i][j][k] = 1;
			}
		}
	}
	// 使用循环来打印数组的值
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				printf("a[%d][%d][%d] = %d\n", i, j, k, a[i][j][k]);
			}
		}
	}
}
#endif

int main()
{
	char str[] = "glad to";
	int str2[] = {1,2,3};
	char *p1 = str;
	// char *p2 = str2;
	int len11, len12;
	int len21, len22;
	p1++;
	// p2++;

	printf("%s\n", p1);
	// printf("%s\n", p2);

	len11 = strlen(str);
	len12 = sizeof(str);

	printf("strlen = %d, sizeof = %d\n", len11, len12);

	// len21 = strlen(str2);
	len22 = sizeof(str2);

	printf("strlen = %d\n", len22);

	return 0;
}
