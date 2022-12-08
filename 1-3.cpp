#include<stdio.h>
int i1,i2;
int sum;
int main()
{
	printf("請輸入第一個數字：");
	scanf("%d",&i1);
	printf("請輸入第二個數字：");
	scanf("%d",&i2);
	sum=i1+i2;
	printf("%d+%d=%d",i1,i2,sum);
	return 0;
 } 
