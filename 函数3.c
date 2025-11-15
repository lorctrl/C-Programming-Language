
#include<stdio.h>
void order(int a,int b)
{
	int t;
	if(a>b){
		t = a;
		a = b;
		b = t;
	}
	
	printf("从小到大的顺序为:%d  %d\n",a,b);
}

int main()
{
	int x,y;
	printf("请输入两个整数：");
	scanf("%d%d",&x,&y);
	order(x,y);
}













