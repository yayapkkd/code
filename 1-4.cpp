#include<stdio.h>
int i1,i2,i3;
int sum;
int main()
{
	printf("請輸入第一個數字：");
	scanf("%d",&i1);
	printf("請輸入第二個數字：");
	scanf("%d",&i2);
	printf("請輸入第三個數字：");
	scanf("%d",&i3);
	sum=i1+i2+i3;
	printf("%d+%d+%d=%d",i1,i2,i3,sum);
	return 0;
 } 
