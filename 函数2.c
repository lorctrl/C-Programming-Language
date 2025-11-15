
#include<stdio.h>
long cube(long x)
{
	long z;
	z = x*x*x;
	return z;
}

void main()
{
	long a,b;
	printf("请输入一个整数：");
	scanf("%d",&a);
	b=cube(a);
	printf("%ld的立方为：%ld",a,b);
	
	return 0;
}











