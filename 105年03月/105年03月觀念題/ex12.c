#include <stdio.h>

void f1(int m);
void f2(int n);
void f1 (int m) {
    printf ("I am in f1\n");
    if (m > 3) {
        printf ("%d\n", m);
        return;
    }
    else {
        printf ("%d\n", m);
        f2(m+2);
        printf ("%d\n", m);
    }
}
void f2 (int n) {
	printf ("I am in f2\n");
    if (n > 3) {
        printf ("%d\n", n);
        return;
    }  
    else {
        printf ("%d\n", n);
        f1(n-1);
        printf ("%d\n", n);
    }
}
int main(void)
{
    f1(1);
    return 0;   
} 
