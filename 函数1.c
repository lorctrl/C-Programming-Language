
#include<stdio.h>
void printstar()
{
	printf("***************");
}

int sum(int a,int b){
	return a+b;
}

int main()
{
	int x = 2,y = 3,z;
	printstar();
	z = sum(x,y);
	printf("\n%d+%d=%d\n",x,y,z);
	printstar();
}



















