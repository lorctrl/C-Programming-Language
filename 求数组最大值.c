
#include<stdio.h>
#define MAXELS 5
void findMAX(int vals[MAXELS]);  // 定义函数
int main(){
	
	int nums[MAXELS] = {2,98,1,27,16};
	findMAX(nums);
	return 0;
}

// 函数体
void findMAX(int vals[MAXELS]){
	
	int i,max = vals[0];
	for(int i=1;i<MAXELS;i++) // 这里应该是小于，不能有等于，否则会越界
		if(max < vals[i])
			max = vals[i];
	printf("The maximum value is %d\n",max);
	
	
	
	
}










