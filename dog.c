#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int i,n,t,k,x,y;
	int dead=0;
	int maze[x][y];
	srand((unsigned)time( NULL ) );
	int a=rand()%4+1;
	//printf("%d\n",a);
	printf("請輸入N：");
	scanf("%d",&n);
	printf("請輸入願意給狗狗的機會：");
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		for (x=1;x<=n;x++)
		{
			for (y = 1; y <= n; y++)
			{
				
				if(x==n/2+1&&y==n/2+1)
				{
					printf("*");
					
				}
					
				else
				printf("0");
			}
			
		printf("\n");
		
		}
		while(x>0 && x<n-1 ,y>0 && y<n-1)
		{
			x=n/2+1;
			y=n/2+1;
			if(maze[x-1][y]!=0 || maze[x+1][y]!=0 || maze[x][y-1]!=0 || maze[x][y+1]!=0)
			{
				dead++;
				break;
			}
			else if (a==1)
			{
				maze[x-1][y]='*';
				printf("%d",maze[x][y]);
			}	
			else if (a==2)
			{
				maze[x+1][y]='*';
				printf("%d",maze[x][y]);
			}			
			else if (a==3)
			{
				maze[x][y-1]='*';
				printf("%d",maze[x][y]);
			} 
								
			else if (a==4)
			{
				maze[x][y+1]='*';
				printf("%d",maze[x][y]);
			} 
							
		}
	

	printf("已死亡%d次\n\n",dead);
	
	}
	printf("\n死亡率 %d%%\n",dead/t*100);
}
	
 
