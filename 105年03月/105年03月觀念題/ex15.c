#include <stdio.h>
void f(int n) {
    printf ("%d\n", n);
    while (n != 1) {
        if ((n%2)==1) {
            n = 3*n + 1;
        }
        else {
            n = n / 2;
        }
        printf ("%d\n", n);
    }
}

int main(void)
{
    f(22); 
    return 0;   
}
