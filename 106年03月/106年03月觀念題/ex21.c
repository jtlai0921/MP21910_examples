#include <stdio.h>

int F (int x,int y) {
    if (x<1)
        return 1;
    else
        return F(x-y,y)+F(x-2*y,y);
}

int main () {
    printf("%d",F(5,2));
    return 0;
}
