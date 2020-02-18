#include <stdio.h>

int main(void)
{
    int i, sum, arr[10];
    for (int i=0; i<10; i=i+1)
        arr[i] = i;
    sum = 0;
    for (int i=1; i<9; i=i+1)
        sum = sum - arr[i-1] + arr[i] + arr[i+1];
    printf ("%d", sum);

    return 0; 
} 
