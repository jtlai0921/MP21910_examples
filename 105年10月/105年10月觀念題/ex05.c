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
    int a[9] = {1, 3, 5, 7, 9, 8, 6, 4, 2};
    int n=9, tmp;
    /* 底下迴圈頭尾交換兩次，又回到原來順序*/
    for (int i=0; i<n; i=i+1) {
        tmp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = tmp;
    }

    for(int i=0;i<=n-1;i++) {
	    printf("%d ",a[i]);
    }            
	printf("\n");
    for (int i=0; i<=n/2; i=i+1)
         printf ("%d %d ", a[i], a[n-i-1]);
  
    return 0; 
} 
