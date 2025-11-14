#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int target,guess,attempts = 0;
	
	// 设置随机数种子
	srand(time(0));
	target = rand() % 100 + 1;  // 生成1~100的随机数
	
	printf("=== 猜数字游戏 ===\n");
	printf("我已经想了一个1~100之间的数字，猜猜看是多少？\n");
	
	do{
		printf("请输入你的猜测：");
		scanf("%d",&guess);
		attempts++;
		
		if(guess > target){
			printf("太大了！再试一次。\n");
		}
		else if(guess <target){
			printf("太小了！再试一次。\n");
		}
		else{printf("恭喜你！猜对了！\n");
			printf("你用了 %d 次猜中。\n",attempts);	
		}
		
		//给提示
		if(attempts == 5){
			int range = target / 10;
			printf("提示：这个数字在%d0~%d9 之间\n",range,range);
		}	
		
	}while(guess != target);
	
	//评价
	if(attempts <= 3){
		printf("太厉害了！\n");
	}
	else if(attempts <= 6){
		printf("还不错！\n");
	}
	else{
		printf("要多加练习哦！\n");
	}

	return 0;
}













