#include <stdio.h>

int G (int B) {
    printf ("自己加入用來追蹤值的B= %d \n", B);
    B = B * B;
    return B;
}

int main(void)
{
    int A=0, m=5;
    A = G(m);
    printf ("自己加入用來追蹤值的A= %d \n", A);
    if (m < 10) { 
        A = G(m) + A;
        printf ("自己加入用來追蹤值的A= %d \n", A);
    } 
    else
        A = G(m);

    printf ("原題目要追蹤的最終的A值= %d \n", A);
    return 0;
}
