#include <stdio.h>

int main(void)
{
    for (int i=0; i<=3; i=i+1) {
        for (int j=0; j<i; j=j+1)
            printf(" ");
        for (int k=6-2*i; k>0 ; k=k-1)
            printf("*");
        printf("\n");
    }
    
    return 0; 
} 
