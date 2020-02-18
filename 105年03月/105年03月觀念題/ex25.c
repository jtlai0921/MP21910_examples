#include <stdio.h>

int Mystery (int x) {
    if (x <= 1) {
        return x;
    }
    else {
        return Mystery(x-2) + Mystery(x-1) ;
    }
}

int main(void)
{
	printf("Mystery(9)=%d",Mystery(9));
    return 0;   
}  
