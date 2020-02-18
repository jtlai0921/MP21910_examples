#include <stdio.h>

int A[8]={0, 2, 4, 6, 8, 10, 12, 14};

int Search (int x) {
    int high = 7;
    int low = 0;
    while (high > low) {
        int mid = (high + low)/2;
        if (A[mid] <= x) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    } 
     return A[high];
}

int main(void)
{
    printf("%d \n",Search(-1)); //結果值0, 答案正確 
    printf("%d \n",Search(0));  //結果值2, 答案正確
    printf("%d \n",Search(10)); //結果值12, 答案正確
    printf("%d \n",Search(16)); //結果值14, 答案錯誤,因為此值沒有大於 16 
    return 0; 
} 
