// 二维数组应用：求对角元素之和

#include<stdio.h>
int main()
{
	float a[3][3],sum = 0;	// 定义三行三列数组
	int i,j;
	printf("请输入3*3个元素：\n");
	
	// 循环输入9个数
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%f",&a[i][j]);
		}
	}
	
	for(int i=0;i<3;i++){
		sum = sum + a[i][i];
	}
	printf("对角线元素和为 %6.2f\n",sum);
	return 0;
}



