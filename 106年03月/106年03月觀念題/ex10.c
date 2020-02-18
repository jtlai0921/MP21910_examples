#include <stdio.h>

int n = 0;
void K (int b) {
    n = n + 1;
    if (b % 4) //只有整除時才會得到 0 (false) 
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
	//printf("%d ",n);  //輸出1 
	//G(2); 
	//printf("%d ",n);    //輸出5, 增加4 
	//G(3); 
    //printf("%d ",n);    //輸出8, 增加3 
	//G(4); 
	//printf("%d ",n);    //輸出10, 增加2 
	//G(5); 
	//printf("%d ",n);    //輸出11, 增加1
	//G(6); 
	//printf("%d ",n);    //輸出15, 增加4 
	G(100); 
	printf("%d ",n);
    return 0;
}
