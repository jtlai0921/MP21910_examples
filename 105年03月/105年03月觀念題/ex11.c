#include <stdio.h>

int g(int a) {
    if (a > 1) {
        return g(a - 2) + 3;
    }
    return a;
}
int main(void)
{

    int i, hold, n;
    n=8;
    int a[]={1,3,5,7,9,6,7,8};

    for (i=0; i<= n-2; i=i+1) {
        hold = a[i];
        a[i] = a[i+1];
        a[i+1] = hold;
    }
    for(i=0;i<=n-1;i++) {
	    printf ("%d\n", a[i]);
    }
    return 0;   
} 
