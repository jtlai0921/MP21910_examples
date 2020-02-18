#include <stdio.h>
#define M 3
#define N 2

int main(void)
{
	int A[M][N]={1,2,
	             3,4,
				 5,6};
   int rowsum = 0;
   for (int i=0; i<M; i=i+1) {
       for (int j=0; j<N; j=j+1) {
           rowsum = rowsum + A[i][j];
       }
       printf("The sum of row %d is %d.\n", i, rowsum);
    }

    return 0; 
}
