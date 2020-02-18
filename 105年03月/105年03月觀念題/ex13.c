#include <stdio.h>

int main(void)
{
    int i,j,k;
    i = 76;
    j = 48;
    while ((i % j) != 0) {
        k = i % j;
        i = j;
        j = k;
    }
    printf ("%d\n", j);

    return 0;   
} 
