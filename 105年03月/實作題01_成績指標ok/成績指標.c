#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int l) {
	int i, j;
	int v;
	//秨﹍逼 
	for(i = 0; i < l - 1; i ++)
		for(j = i+1; j < l; j ++)
		{
			if(a[i] > a[j])
			{
				v = a[i];
				a[i] = a[j];
				a[j] = v;
			}
		}
}

int main(void) {
	int i;
	int n;	
	printf("叫块厩ネ计: "); 
	scanf("%d", &n);
	int num[21];
	printf("叫块厩ネΘ罿: "); 
	for (i=0;i<=n-1;i++)	
		scanf("%d", &num[i]);
	sort(num,n);//盢Θ罿秈︽逼 
	
	//盢逼Θ縩パ 
	for (i=0;i<=n-1;i++)			
		printf("%d ",num[i]);
	printf("\n");
	
	if (num[0]>=60) {
		printf("best case \n");//狦场だ计常60,ボ程ㄎ猵 
		printf("%d \n",num[0]);//程のだ计 
	}	
	else if (num[n-1]<60){
		printf("%d \n",num[n-1]);//程蔼ぃのだ计 
		printf("worst case \n"); //狦场だ计常60,ボ程畉猵 
	}
	else {
		for (i=n-1;i>=0;i--)
			if (num[i] <60){
				printf("%d\n",num[i]);
				break;
			}
		for (i=0;i<=n-1;i++)
			if (num[i] >=60){
				printf("%d\n",num[i]);
				break;
			}
	}
	return 0;
}
