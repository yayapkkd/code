#include <stdio.h>
#include <string.h>
#define Max 100
int main(void) 
{
    char arr[Max];
    int i,j,x=0,y=0;
    scanf("%s", &arr);
    size_t length = strlen(arr);
    if(arr[0] == '0' && length %2 == 0){
        for(i = 0 ; i < Max ; i++){
        	if(arr[i] == '0'){
                x++;
            }
        }
        for(j = x-1 ; j < Max ; j++){
            if(arr[j]=='1'){
                y++;
			}
        }
	}
	else{
        printf("false\n");
        return;
    }
    printf("true\n");
}
