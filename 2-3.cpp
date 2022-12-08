#include <stdio.h>
int cal_sum(int sum)
{
	if(sum<3)
		return 1;
	return cal_sum(sum-1)+cal_sum(sum-2);
}


int main(int argc,const char **argv)
{
	printf("請輸入月數：\n");
	
	int a;
	scanf("%d",&a);
	printf("第%d個月有：%d對小兔子\n",a,cal_sum(a));
	
	return 0;
}
