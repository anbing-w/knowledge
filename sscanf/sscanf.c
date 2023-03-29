#include <stdio.h>
#include <string.h>

int main(int argc,char** argv)
{
	const char* in = "a1b2c3ABCdef 123";
	char out[100] = {0};
 
	sscanf(in,"%3s", out);
	printf("��ȡǰ3���ַ�:%s\n",out);
 
	memset(out,0,sizeof(out));
	sscanf(in,"%*3s%3s", out);
	printf("����3���ַ����ȡǰ3���ַ�:%s\n",out); 
 
	memset(out,0,sizeof(out));
	sscanf(in,"%*[^A]A%3s", out);
	printf("���Կ�ͷ��A�ַ�������ȡǰ3���ַ�:%s\n",out);
	
	memset(out,0,sizeof(out));
	sscanf(in,"a%[0-9]", out); //����%dŶ�����������־�ֹͣ
	printf("��ȡ����:%s\n",out);
 

	memset(out,0,sizeof(out));
	sscanf(in,"a1b2c3%[a-zA-Z]", out); //�������־�ֹͣ
	printf("��ȡСд+��д��ĸ:%s\n",out);

	memset(out,0,sizeof(out));
	sscanf(in,"%*[a-zA-Z]%[^\0]", out); 
	printf("22222:%s\n",out);

    
	memset(out,0,sizeof(out));
	sscanf(in,"%[^a-zA-Z]", out); //��������Сд��ĸ�ʹ�д��ĸ��ֹͣ
	printf("33333:%s\n",out);

	return 0;
}