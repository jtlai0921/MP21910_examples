#include <stdio.h>

int K(int a[], int n) {
    if (n >= 0)
        return (K(a, n-1) + a[n]);
    else
        return 0;
}
int G(int n){
    int a[] = {5,4,3,2,1};
    return K(a, n);
}

int main(void)
{
    printf("%d",G(3));
    return 0; 
} 
