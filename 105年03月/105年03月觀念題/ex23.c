#include <stdio.h>

int f(int n) {
    int p = 0;
    int i = n;
    while (i >= 1) {
        p=10-2*i;
        printf ("%d", p);
        i = i - 1 ;
    }
}
int main(void)
{
	f(4);
    return 0;   
}  
