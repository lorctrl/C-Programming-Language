#include<stdio.h>

int main()
{
	int choice;
	double num1,num2,result;
	char countinue_calc;
	
	printf("欢迎使用简易计算器！\n");
	
	do{
		// 显示菜单
		printf("\n请选择要执行的操作:\n");
		printf("1. 加法\n");
		printf("2. 减法\n");
		printf("3. 乘法\n");
		printf("4. 除法\n");
		printf("5. 退出\n");
		printf("请输入选项(1~5)：");
		
		scanf("%d",&choice);
		
		//处理退出选项
		if(choice == 5){
			printf("感谢使用，再见！");
			break;
		}
		
		//输入两个数字
		printf("请输入第一个数字：");
		scanf("%lf",&num1);  // 使用的double所以用 %lf
		
		printf("请输入第二个数字：");
		scanf("%lf",&num2);
		
		// 根据选择执行相应计算
		switch (choice) {
		case 1: //加法
			result = num1 + num2;
			printf("%.2lf + %.2lf = %.2lf",num1,num2,result);
			break;
		case 2: //减法
			result = num1 - num2;
			printf("%.2lf - %.2lf = %.2lf",num1,num2,result);
			break;
		case 3: //乘法
			result = num1 * num2;
			printf("%.2lf * %.2lf = %.2lf",num1,num2,result);
			break;
		case 4: //除法
			if(num2 != 0)
			{
				result = num1 / num2;
				printf("%.2lf / %.2lf = %.2lf",num1,num2,result);	
			}
			else
			{
				printf("除数错误");
			}
			break;			
		default:
			printf("无效的选项，请重新选择！");
			break;
		}
		
		// 询问是否继续计算
		if(choice >=1 && choice <= 4){
			printf("\n是否继续计算(y/n) :");
			scanf(" %c",&countinue_calc);
		}
		
	} while(choice != 5 && countinue_calc != 'n' && countinue_calc != 'N');
	
	return 0;
}

















