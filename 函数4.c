
#include<stdio.h>
void swap(int a,int b)
{
	int temp;
	temp=a;a=b;b=temp;
	printf("a=%d,b=%d\n",a,b);
}

int main()
{
	int x,y;
	printf("请输入两个整数：\n");
	scanf("%d%d",&x,&y);
	printf("调用函数之前：\n");
	printf("x=%d,y=%d\n",x,y);
	printf("调用函数中···\n");
	swap(x,y);
	printf("调用函数之后：\n");
	printf("x=%d,y=%d\n",x,y);
	
	return 0;
}














