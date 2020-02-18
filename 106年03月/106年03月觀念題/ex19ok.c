#include <stdio.h>

int main () {
    int M = -1, N = 101, s = 3;
    int A[] = {80,90,100};
    for (int i=0; i<s; i=i+1) {
        if (A[i]>M) {
            M = A[i];
        }
        if (A[i]<N) {
            N = A[i];
        }
    }
    printf("M = %d, N = %d\n", M, N);
    return 0;
}
