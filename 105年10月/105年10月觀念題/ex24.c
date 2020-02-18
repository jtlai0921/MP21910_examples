#include <stdio.h>
int G (int a, int x) {
    if (x == 0)
        return 1;
    else
        return (a * G(a, x - 1));
}

int main(void)
{ 
    printf ("%d \n", G(3,7));
    return 0;
} 
