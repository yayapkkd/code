#include<stdio.h>
int i1,i2,a;
int main()
{
	printf("請輸入第一個數字：");
	scanf("%d",&i1);
	printf("請輸入第二個數字：");
	scanf("%d",&i2);
	a=i1;
	i1=i2;
	i2=a;
	printf("交換後\n第一個數字為%d\n第二個數字為%d",i1,i2);
	return 0;
 } 
