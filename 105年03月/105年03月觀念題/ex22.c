#include <stdio.h>

int f() {
    int p = 2;
    while (p < 2000) {
        p = 2 * p;
    }
    return p;
}
int main(void)
{
    f();
    printf("f()=%d",f());
    return 0;   
}
