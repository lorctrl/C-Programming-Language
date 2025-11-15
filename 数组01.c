#include<stdio.h>
#define MAXGRADES 5
int main()
{
	int code[MAXGRADES];
	int i;
	
	// 输入数据
	for(int i=0;i<=MAXGRADES;i++){
		printf("输入一个数据：");
		scanf("%d",&code[i]);
	}
	
	// 输出数据
	for(int i=0;i<=MAXGRADES;i++){
		printf("code[%d] = %d\n",i,code[i]);
	}
	
	return 0;
}
