#include <stdio.h>

int G (int a, int x) {
    if (x == 0)
        return 1;
    else
        return ((2*a)+2) * G(a, x - 1) ;
}

int main(void)
{
    printf("選項A的結果:\n");
    for(int x=0;x<=5;x++){
  	    printf("%d \n",G(2,x));
    }
  
    return 0;
}
