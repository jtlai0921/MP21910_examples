#include <stdio.h>

int main(void)
{
    for (int i=0; i<=10; i=i+1) {
        printf ("%d ", i);
        i = i + 1;
    }
    printf ("\n");
    return 0;   
}
