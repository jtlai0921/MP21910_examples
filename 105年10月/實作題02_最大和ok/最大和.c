#include <stdio.h>
#define testdata "data1.txt"

int main(void) {
	FILE *fp;
	int number[20][20];
	int BIG[20];
	int N; //N群數字 
	int M; //每群有M個正整數 
	
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
	for (i=0;i<N;i++)  //求各群組整數中最大值的總和 
		sum=sum+BIG[i];
		
	printf("%d \n",sum);
	//找各群組中最大值能整除sum的數字 
	char flag='N';	
	for (i=0;i<N;i++){
		if(sum % BIG[i]==0){
			flag='Y';
			printf("%d ",BIG[i]);
		}
	}
	if (flag=='N') //如果找不到整除者, 則輸出-1 
		printf("-1 \n");
	
	return 0;
}
