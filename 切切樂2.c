#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x,n,arr[100]={0},count=-1;
    char y;

        do{
            scanf("%d",&arr[n]);
            n++;
            count++;
        }while(y=getchar()==',');

    for(n=0;n<=count;n++)
    {

        if(arr[n]>arr[n+1])
        {
            x=count-(n+1);
            break;
        }

    }
        printf("%d\n",x);
    return 0;
}
