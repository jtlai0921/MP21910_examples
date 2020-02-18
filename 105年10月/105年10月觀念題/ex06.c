#include <stdio.h>

int F(int a) {
    if ( a<0)
        return 1;
    else
        return F(a-2) + F(a-3);
}

int main(void)
{
	printf("%d",F(7));
    
    return 0; 
} 
