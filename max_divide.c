#include<stdio.h>
#include<stdlib.h>
int *max_divide(char arr[ ][20], int n);

int *max_divide(char arr[ ][20], int n)
{
	int i,ans;
	for (i = 0; i < n; i++)
    {
		if(((arr[i+1])-arr[i])==(arr[i+2])-(arr[i+1]))
		{
			if(((arr[i+1])-arr[i])<0)
			{
				ans=0;
			}
			else
			{
				ans=ans+1;
			}
		}

    }
	printf("%d",ans+1);
}
