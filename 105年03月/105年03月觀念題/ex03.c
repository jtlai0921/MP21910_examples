#include <stdio.h>

int f1(int a[], int value) {
    int r_value = -1;
    int i = 0;
    int n1=0;
    while (i < 100) {
        n1=n1+1;
        if (a[i] == value) {
            r_value = i;
            break;
        }
        i = i + 1;
    }
    printf("n1=%d\n", n1);
    return r_value;
}

int f2(int a[], int value) {
    int r_value = -1;
    int low = 0, high = 99;
    int mid;
    int n2=0;
    while (low <= high) {
 	    n2=n2+1;
        mid = (low + high)/2;
        if (a[mid] == value) {
            r_value = mid;
            break;
        }
        else if (a[mid] < value) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    printf("n2=%d\n", n2);
    return r_value;
}

int main(void)
{
    int a[100];
    int i;
    for (i=0;i<=99;i++)
        a[i]=3*i+1;
    f1(a,100);
    f2(a,100);     
    return 0; 
} 
