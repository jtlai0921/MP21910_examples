#include <stdio.h>

int main(void) {
	int no[50000];
	int marked[50000];
	int i,n;
	int num; //�h�֭Ӥp�s�骺�p�ƾ� 
	
	scanf("%d",&n); //Ū������H�� 
	for (i=0;i<=n-1;i++){		
		scanf("%d",&no[i]); //�q0��N�̧�Ū���U�n�ͽs�� 
		marked[i]=0;//��ȳ]�w�C�@�ӽs�����|�����X 
	}
	i=0;  
	num=0;//�k�s 
	int find=0; //�p�G�٨S���p�s��w�]�Ȭ�0 
	int head;
	while (find==0) { 
		head=i;//�����C�@�Ӥp�s�骺�Y 	
		while (no[i]!=head && marked[i]==0 ){
			marked[i]=1; //�]�w�w���X
			i=no[i];	//�~�򱴳X�L���n��		
		}
		num++;	//�֥[���h�֭Ӥp�s��
		marked[i]=1;	 //�]�w�w���X	
		find=1;  //��ܤw���Q���p�s��
		//�̧ǧ�X���b�w��쪺�s�餤�B�S�����X�̡A�q�ӽs���}�l���X 
		for (i=0 ;i<=n-1;i++)
			if (marked[i]==0){
				find=0;
				break;
			}
	}
	printf("%d",num);
	return 0;
}
