#include <stdio.h>

int F (int n) {
    if (n < 4)
        return n;
    else
        return n + F(n-3);
}

int main(void)
{
	printf("%d ",F(14));
    
    return 0; 
}
