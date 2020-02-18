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
    printf("%d \n",Search(-1)); //���G��0, ���ץ��T 
    printf("%d \n",Search(0));  //���G��2, ���ץ��T
    printf("%d \n",Search(10)); //���G��12, ���ץ��T
    printf("%d \n",Search(16)); //���G��14, ���׿��~,�]�����ȨS���j�� 16 
    return 0; 
} 
