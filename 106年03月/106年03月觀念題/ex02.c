#include <stdio.h>

void F (int x) {
    int i;
    for (i=0; i<x; i=i+1)
        printf("*");
    if (x>1) {
        F(x/2);
        F(x/2);
    }
}

void A1 (int n) {
    F(n/5);
    F(4*n/5);
}

void A2 (int n) {
    F(2*n/5);
    F(3*n/5);
}

int main(void)
{
    printf("�ﶵA�����浲�G:  \n");
    A1(5);
    printf("\n");
	A2(5); 
	printf("\n\n");
    
    printf("�ﶵB�����浲�G:  \n");
    A1(13);
    printf("\n");
	A2(13); 
	printf("\n\n");
	
	printf("�ﶵC�����浲�G:  \n");
    A2(14);
    printf("\n");
	A1(14); 
	printf("\n\n");
    
    printf("�ﶵD�����浲�G:  \n");
    A2(15);
    printf("\n");
	A1(15); 
	printf("\n\n");
    
    return 0; 
} 
