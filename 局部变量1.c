#include<stdio.h>
int main()
{
	char str1[10],str2[10];
	char *p1,*p2;
	p1 = str1;
	p2 = str2;
	printf("请输入原字符串：");
	gets(p2);
	for(;*p2 != '\0';p1++,p2++){
		*p1 = *p2;
	}
	*p1 = '\0';
	printf("原字符串是：%s\n复制后字符串是：%s",str2,str1);
	return 0;
}













