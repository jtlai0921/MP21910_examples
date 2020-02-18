#include <stdio.h>
#include <stdlib.h>
#define testdata "data1.txt"
#define SIZE 100000

void get_height(int); //���o�C�Ӹ`�I������ 
void print_root(int); //�N��쪺�𪬹Ϫ��ڸ`�I�s���L�X 
long total(int);  //��ƭ쫬�ŧi,�^�ǩҦ��`�I�̤j�����`�M 

int parents[SIZE]={0}; //�O���C�Ӹ`�I���`�I
int height[SIZE]={0}; //�O���C�Ӹ`�I������
int child_no[SIZE]={0}; //�O���C�Ӹ`�I���l�`�I�ƶq

int main(void){  
    FILE *fp;
	int n; //�`�I���Ӽ� 
	int temp;
	long sum_of_height;
	
	fp=fopen(testdata,"r");
	fscanf(fp,"%d",&n); //�q�ɮפ�Ū���𪬹Ϫ��`�I�Ӽ� 
	for (int i=1; i<=n;i++){
		fscanf(fp,"%d",&child_no[i]); //Ū���`�I���s�� 1 �� n���l�`�I�Ӽ� 
		for (int j=1; j<=child_no[i];j++){
			fscanf(fp," %d",&temp); //�̧ǨC�@�Ӹ`�I���l�`�I�s�� 
			parents[temp]=i; //�O���o�Ǥl�`�I�����`�I�s�� 
		}
	}
	print_root(n);//��X�ڸ`�I���s�� 
    get_height(n);//���o�U�`�I������ 
    sum_of_height=total(n);//�p��U�`�I�������`�M 
    
    printf("%ld",sum_of_height);//��X�Ҧ��`�I�������`�M 
    return 0;
}
//�N��쪺�𪬹Ϫ��ڸ`�I�s���L�X
void print_root(int n){
	for(int i=1;i<=n;i++){
		if(parents[i]==0)
		    printf("%d\n", i);
	}
}
//���o�C�Ӹ`�I������
void get_height(int n){
	for(int i=1; i<=n;i++){
		if(child_no[i]==0){
			int tall=0; //�O���n�p��`�I������
			int node =parents[i]; //���ʨ� i �����`�I
			while (node!=0){
				tall++;
				if(tall>height[node]){
					height[node]=tall;
				} 
				node=parents[node];	 
		    }
		}
	}
} 
//�^�ǩҦ��`�I�̤j�����`�M
long total(int n){
	long sum=0; //�̤j����
	for(int i=1 ; i<=n ; i++){
    	sum = sum + height[i];
    }
	return sum;
}
