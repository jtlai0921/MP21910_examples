#include <stdio.h>

int f (int a[], int n) {
    int index = 0;
    for (int i=1; i<=n-1; i=i+1) {
    	printf("i=%d a[%d]=%d \n", i,i,a[i]);
    	printf("index=%d a[%d]=%d \n", index,index,a[index]);
        if (a[i] >= a[index]) {
            index = i;
       }
    }
    return index;
}
int main(void)
{
    int a[10]={1,3,9,2,5,8,4,9,6,7};
    printf("回傳後的 index= %d", f(a,10));
    return 0;   
} 
