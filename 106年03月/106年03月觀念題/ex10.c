#include <stdio.h>

int n = 0;
void K (int b) {
    n = n + 1;
    if (b % 4) //�u���㰣�ɤ~�|�o�� 0 (false) 
        K(b+1);
}

void G (int m) {
    for (int i=0; i<m; i=i+1) {
        K(i);
    }
}

int main(void)
{
	//G(1); 
	//printf("%d ",n);  //��X1 
	//G(2); 
	//printf("%d ",n);    //��X5, �W�[4 
	//G(3); 
    //printf("%d ",n);    //��X8, �W�[3 
	//G(4); 
	//printf("%d ",n);    //��X10, �W�[2 
	//G(5); 
	//printf("%d ",n);    //��X11, �W�[1
	//G(6); 
	//printf("%d ",n);    //��X15, �W�[4 
	G(100); 
	printf("%d ",n);
    return 0;
}
