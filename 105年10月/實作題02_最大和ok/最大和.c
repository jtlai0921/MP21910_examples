#include <stdio.h>
#define testdata "data1.txt"

int main(void) {
	FILE *fp;
	int number[20][20];
	int BIG[20];
	int N; //N�s�Ʀr 
	int M; //�C�s��M�ӥ���� 
	
	fp=fopen(testdata,"r");
	fscanf(fp,"%d %d", &N, &M);	
	
	int i,j;	
	for (i=0;i<N;i++)
        for (j=0;j<M;j++)			
            fscanf(fp,"%d", &number[i][j]);	
	
	for (i=0;i<N;i++){
        BIG[i]=number[i][0];
        for (j=1;j<M;j++){			
            if (number[i][j]>BIG[i])
            BIG[i]=number[i][j];			
        }		
    }
	
	int sum=0;
	for (i=0;i<N;i++)  //�D�U�s�վ�Ƥ��̤j�Ȫ��`�M 
		sum=sum+BIG[i];
		
	printf("%d \n",sum);
	//��U�s�դ��̤j�ȯ�㰣sum���Ʀr 
	char flag='N';	
	for (i=0;i<N;i++){
		if(sum % BIG[i]==0){
			flag='Y';
			printf("%d ",BIG[i]);
		}
	}
	if (flag=='N') //�p�G�䤣��㰣��, �h��X-1 
		printf("-1 \n");
	
	return 0;
}
