#include <stdio.h>
int a(int n, int m) {
    if (n < 10) {
        if (m < 10) {
            return n + m ;
        }
        else {
            return a(n, m-2) + m ;
        }
    }
    else {
        return a(n-1, m) + n ;
    }
}
int main(void)
{	
    printf("���G��: %d\n",a(13,15));
    return 0;   
} 
