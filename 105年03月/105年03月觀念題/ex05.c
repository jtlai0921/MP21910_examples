#include <stdio.h>
int f (int n) {
    int sum=0;
    printf("n= %d\n",n);
    if (n<2) {
        return 0;
    }
    for (int i=1; i<=n; i=i+1) {
        sum = sum + 1;
    }
    sum = sum + f(2*n/3);
    return sum;
}
int main(void)
{
	int temp;
    printf("°õ¦æ¦¸¼Æ: %6d\n",f(1000));
    return 0;   
}
