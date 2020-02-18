#include <stdio.h>

int g(int a) {
    if (a > 1) {
        return g(a - 2) + 3;
    }
    return a;
}
int main(void)
{
    printf ("%d\n", g(13));
 
    return 0;   
} 
