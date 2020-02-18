#include <stdio.h>

void F (int n) {
    printf ("%d\n" , n);
    if ((n%2 == 1) && (n > 1)){
        return F(5*n+1);
    }
    else {
        if (n%2 == 0)
            return F(n/2);
    }
}

int main(void)
{
    F(15); 
	
    return 0;
}
