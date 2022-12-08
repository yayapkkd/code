#include<stdio.h>
#include<stdlib.h>
int x_sum(int arr[], int sum);
void Sort(char arr[],int sum);

int x_sum(int arr[], int sum)
{
	int i,j,k;
	for(i=0;i<6;i++)
	{
		for(j=i+1;j<=6;j++)
		{
			for(k=j+1;k<=6;k++)
			{
				if(arr[i]+arr[j]+arr[k] == 0)
				{
					printf("%d,%d,%d\n%",arr[i],arr[j],arr[k]);
					sum++;
				}
			}
		}
	}
	printf("¦@%dµ§",sum);
	return 0;
}

void Sort(char arr[],int sum)
{
	int i,j,t;
 	for(i=0;i<sum;i++)
 	{
  		for(j=0;j<sum;k++) 
  		{
   			if(arr[j] > arr[j+1]) 
   			{
    			t = arr[j];
    			arr[j] = arr[j+1];
    			arr[j+1] = t;
   			}
  		}
 	}
 }

