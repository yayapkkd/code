//只能輸入一組數字 

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j, k, l, val, n, row, column, count;
	char add[3];
	char num ;
	char num1;
	char A [6] = {'+', '-', '-', '-', '+'};
	char B [9] = {'-', '-', '-', '-', '-', '-', '-', '+'};
	char C [6] = {
   	 [0] = '|',
   	 [1] = ' ',
   	 [3] = ' ',
   	 [4] = '|'};

	char D [9] = {'\0'};

	printf("輸入範例：\nA1  (enter)\n");
	printf("100 (enter)\n");	
	scanf("%s", add);
	scanf("%d", &val);
	column = add[0]- 65 ;
	row = add[1] - 	48;
	//printf("%d %d\n", column, row);
	
	
	for(i=0;i<10;i++)
		{
			printf("%s", A); 
			for(j=0;j<6;j++)
			{
				printf("%s", B);
			
			}
			printf("\n");
			if(i==0)
			{
				C[2] = ' ';
				
			}
			else
			{
				C[2] = i+48;
			}
			printf("%s", C);
			for(k=0;k<6;k++)
			{
				if(i==0)	
				{
					
					D[3] = k + 65;

					D[0] = ' ';
   					D[1] = ' ';
	 				D[2] = ' ';
   	 				D[4] = ' ';
					D[5] = ' ';
					D[6] = ' ';
   	 				D[7] = '|';
   	 				printf("%s", D);

				}
				else if(i==row && k==column)
				{
					printf("%7d|", val);
				}
				else
				{
					printf("       |");
				}
				
				//printf("%s", D);

			}
			printf("\n");	
		} 
		
	printf("%s", A);
	for(l=0;l<6;l++)
	{
		printf("%s", B);
	}
	//}
	


	



}
