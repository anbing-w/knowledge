#include <stdio.h>
#include <string.h>

int main(int argc,char** argv)
{
	const char* in = "a1b2c3ABCdef 123";
	char out[100] = {0};
 
	sscanf(in,"%3s", out);
	printf("截取前3个字符:%s\n",out);
 
	memset(out,0,sizeof(out));
	sscanf(in,"%*3s%3s", out);
	printf("跳过3个字符后截取前3个字符:%s\n",out); 
 
	memset(out,0,sizeof(out));
	sscanf(in,"%*[^A]A%3s", out);
	printf("忽略开头到A字符串，截取前3个字符:%s\n",out);
	
	memset(out,0,sizeof(out));
	sscanf(in,"a%[0-9]", out); //不是%d哦，遇到非数字就停止
	printf("提取数字:%s\n",out);
 

	memset(out,0,sizeof(out));
	sscanf(in,"a1b2c3%[a-zA-Z]", out); //遇到数字就停止
	printf("提取小写+大写字母:%s\n",out);

	memset(out,0,sizeof(out));
	sscanf(in,"%*[a-zA-Z]%[^\0]", out); 
	printf("22222:%s\n",out);

    
	memset(out,0,sizeof(out));
	sscanf(in,"%[^a-zA-Z]", out); //遇到任意小写字母和大写字母就停止
	printf("33333:%s\n",out);

	return 0;
}