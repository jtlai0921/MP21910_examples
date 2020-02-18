#include <stdio.h>
#include <math.h>

int F (int n) {
    int x = 0;
    for (int i=1; i<=n; i=i+1)
        for (int j=i; j<=n; j=j+1)
            for (int k=1; k<=n; k=k*2)
                //printf("%d \n",k);
                x = x + 1;
            return x;
}

int main(void)
{
	int n,a;
    n=2;
    printf("%d \n",F(n));
    a=(log(n)/log(2)+1)/1;  
    printf("%d \n",a);
    
    n=4;
    printf("%d \n",F(n));
    a=(log(n)/log(2)+1)/1;  
    printf("%d \n",a);
    
    n=8;
    printf("%d \n",F(n));
    a=(log(n)/log(2)+1)/1;  
    printf("%d \n",a);
    
    n=10;
    printf("%d \n",F(n));
    a=(log(n)/log(2)+1)/1;  
    printf("%d \n",a);
    
    n=16;
    printf("%d \n",F(n));
    a=(log(n)/log(2)+1)/1;  
    printf("%d \n",a);
    
    n=100;
    printf("%d \n",F(n));
    a=(log(n)/log(2)+1)/1;  
    printf("%d \n",a);
	
    return 0;
}
