#include <stdio.h>

int GCD (int a, int b) {
    int r;
    r = a % b;
    if (r == 0)
        return b;
    return GCD(b,r);
}

int main(void)
{   
	printf("%d ",GCD(64,72));
    
    return 0; 
} 
