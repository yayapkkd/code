#include <stdio.h>
int cal_sum(int sum)
{
	if(sum<3)
		return 1;
	return cal_sum(sum-1)+cal_sum(sum-2);
}


int main(int argc,const char **argv)
{
	printf("�п�J��ơG\n");
	
	int a;
	scanf("%d",&a);
	printf("��%d�Ӥ릳�G%d��p�ߤl\n",a,cal_sum(a));
	
	return 0;
}
