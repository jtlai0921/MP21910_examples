#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int l) {
	int i, j;
	int v;
	//�}�l�Ƨ� 
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
	printf("�п�J�ǥͤH��: "); 
	scanf("%d", &n);
	int num[21];
	printf("�п�J�ǥͦ��Z: "); 
	for (i=0;i<=n-1;i++)	
		scanf("%d", &num[i]);
	sort(num,n);//�N���Z�i��Ƨ� 
	
	//�N�Ƨǫ᪺���n�Ѥp��j�L�X 
	for (i=0;i<=n-1;i++)			
		printf("%d ",num[i]);
	printf("\n");
	
	if (num[0]>=60) {
		printf("best case \n");//�p�G�������Ƴ��j��60,��̨ܳΪ��p 
		printf("%d \n",num[0]);//�L�X�̧C�ή���� 
	}	
	else if (num[n-1]<60){
		printf("%d \n",num[n-1]);//�L�X�̰����ή���� 
		printf("worst case \n"); //�p�G�������Ƴ��p��60,��̮ܳt���p 
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
