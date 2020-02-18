#include <stdio.h>
#include <math.h>
#define testdata "data2.txt"

void mysort(int*,int); //mysort�禡�ŧi,�|�N�ǤJ�}�C�Ƨ� 
char isCovered(int); //isCovered�禡�ŧi,�^�ǭȬ��r�� 

int N;  //�A���I�ƥ�
int K;  //��a�x�ƥ�
int P[50000];  //�O���A���I���Z����T 

int main(void) {
    int lower_bound;
    int upper_bound;
	int med;
	FILE *fp;
    
    fp=fopen(testdata,"r");
    fscanf(fp,"%d%d", &N, &K);  //��J�A���I�ΰ�a�x�ƥ� 
    for(int i=0; i<N; i++) {
        fscanf(fp,"%d", &P[i]); 
	}   
	//�Ѥp��j�Ƨ� 
	mysort(P,N);
	//�̤p���|��1�A
	//�̤j���|��floor((�A�ȯ��̤j�y��-�A�ȯ��̤p�y��)/��a�x�Ӽ�) + 1
    //���פ���o��Ƥ����A�ϥΤG���j�M�k��X���סC
	lower_bound = 1;  //�̤p�ȱq1�}�l
	upper_bound = floor((P[N-1]-P[0])/K) + 1;  //�䤤floor��ƥ\��O����ѼƤp���̤j���
	while(lower_bound <= upper_bound) {
		med = floor((lower_bound + upper_bound) / 2);  //�G���j�M�k
		//�p�G�Ǧ^ 'Y',��ܶǤJmed���|���j�p�ŦX����,
		//���۱N���ǤJ�����|�ƭ��Y�p��,�A�i��P�_ 
		if(isCovered(med)=='Y')  
		    upper_bound = med;  
		//�p�G�Ǧ^ 'N',��ܶǤJmed���|���j�p���ŦX����,
		//�A���۱N���ǤJ�����|�ƭ��Y��j��,�A�i��P�_ 
		else  
		    lower_bound = med + 1;  
		if(lower_bound == upper_bound)  
		    break;
	}
	printf("%d\n", med);
	return 0;
}

//�ۭq�Nmysort�禡�A�ǤJ�}�C���ȥѤp��j�Ƨǫ�A�^��
void mysort(int *a, int l) {
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

//�ۭqisCovered�禡�A���թҶǤJ����a�x���|diameter�ѼơA
//�i�_�л\�Ҧ��ڪA���I�A�i�H�h�^�� 'Y"�A���i�H�h�^��'N"
char isCovered(int diameter) {  
	int coverage =0; //��a�x�л\�d�� 
	int number = 0; //��a�x�ƶq���p�ƾ� 
	int pos = 0;//�A���I���޽s���q 0 �}�l 
	
	for (int i=0;i<N;i++) //�q�̫e���A���I�}�l��_ 
	{
		coverage = P[pos] + diameter;  //��a�x���л\�d��
		number++;  //�O����a�x�ƥت��p�ƾ�,���B�n�֥[ 1 
		/* 
		  �p�G��a�x�ƶq�j��K,�h�Ǧ^ 'N',��ܳo�Ӫ��|�j�p
		  �Ҳ[�\���d��,�L�k�����л\�Ҧ��A���I 
		*/ 
		if(number>K)  
		    return 'N';
        //�p�G�[�\�����A���I�B��a�x�ƶq�p��K�h�Ǧ^ 'Y' 
		if((number<=K) && (P[N-1]<=coverage) )  
		    return 'Y';  
		do{  //��������U�@�ӨS���Q�[�\���A���I
            pos++;
	    }while (P[pos]<=coverage);  
	}
}
