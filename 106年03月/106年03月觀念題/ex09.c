#include <stdio.h>

void F () {
    int X[10] = {0};
    for (int i=0; i<10; i=i+1) {
        scanf("%d", &X[(i+2)%10]);
    }
 
    for (int i=0; i<10; i=i+1) {
        printf("%d", X[i]);
    }
}

int main(void)
{
	F(); 
    return 0;
}
