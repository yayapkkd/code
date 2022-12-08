#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int a1,a2,a3;
    char i1,i2,i3;

    a1 = 0;
    i1 = '+';
    while(i1!=getchar()=='\n')
    {
        scanf("%d %c",&a2,&i2);  
        while(i2=='*' || i2=='/')
        {
            scanf("%d %c",&a3,&i3);
            if(i2=='*')
                a2 *= a3;
            else if(i2=='/')
                a2 /= a3;
            i2 = i3; 
        }
        if(i1=='+')
            a1 += a2;
        else if(i1=='-')
            a1 -= a2;
        i1 = i2; 
    }

    printf("%d",a1);

	return 0;
}
