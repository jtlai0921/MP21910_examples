#include <stdio.h>

int s = 1; // 办跑计
void add (int a) {
    int s = 6;  //跋办跑计,Τ絛瞅ㄧ计ず 
    for( ; a>=0; a=a-1) {
        printf("%d,", s);
        s++;
        printf("%d,", s);
    }
}

int main(void)
{
    printf("%d,", s);
    add(s);
    printf("%d,", s);
    s = 9;
    printf("%d", s);
    return 0;
} 
