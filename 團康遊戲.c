#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x,y=-1,ans=0;
 	while(scanf("%d",&x)){
		if(x!=-1){
    		y=-y;
    		ans=ans+y*x;
    	}
    	else{
       		break;
   		}
	}
	printf("%d\n",ans);
}
