#include <stdio.h>

int main(void)
{
    // int A[]={7,5,3,12,9,19,21,43 };
    int A[]={5,5,5,5,5,5,5,5 };
    int n=8;
    int p,q;  
    p = q = A[0];
    for (int i=1; i<n; i=i+1) {
        if (A[i] > p)
            p = A[i];
        if (A[i] < q)
            q = A[i];
        }
        
	printf("%d   %d",q,p);
    
    return 0; 
} 
