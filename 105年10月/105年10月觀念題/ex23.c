#include <stdio.h>

int main(void)
{
    int i=2, x=3;
    int N=65536;
    while (i <= N) {
	    printf ("�L�{���ܤ� %d %d \n", i, x);
        i = i * i * i;
        x = x + 1;
    }
    printf ("%d %d \n", i, x);
  
    return 0;
} 
