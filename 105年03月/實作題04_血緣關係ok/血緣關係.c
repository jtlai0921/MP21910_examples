#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#define testdata "data1.txt"

int distance(int); //��ƭ쫬�ŧi 
int max(int,int);  //��ƭ쫬�ŧi
int swap(int *,int *); //��ƭ쫬�ŧi

int CHILD[10000][2]; //�O���C�즨�����p�ı��p 
int answer=0; //�̲׵���, �O���̪���t�Z�� 
int how_many[10000]={0}; //�O���C�즨�����h�֤p�� 
char other_child[10000]={0}; //�P�_�O�_����L�H���p�� 
int n;  //�a�x�����H�� 

int main(void) {
    FILE *fp; 
    int i;
    int root;  //�a�ڪ��ڸ`�I,�Y���� 
    int from_root;   //�����q�ڸ`�I�X�o���̤j�`�� 
    
    //�q�~���ɮ�Ū����� 
    fp=fopen(testdata,"r");
    fscanf(fp,"%d",&n);  //Ū���a�ڦ����`�� 
    //�v��Ū���U�������p�ĸ�T 
	for(i=0;i<n-1;i++) {
    	fscanf(fp,"%d %d",&CHILD[i][0],&CHILD[i][1]); 
    	how_many[CHILD[i][0]]+=1; 
    	other_child[CHILD[i][1]]=1; //���L�H�p�ĴN�O���� 1 
	}
	//��X�𪬹Ϫ��ڸ`�I,�Y����
    for (i=0;i<n;i++) {  
		if (other_child[i]==0) {
			root =i ;
			break;
		}
    }
	from_root=distance(root); //�q�ڸ`�I�X�o���̤j�`�� 
	answer=max(from_root,answer);
	printf("%d", answer);
	
	return 0;
}

//�Ǧ^��ƶ����j�� 
int max(int x,int y) {
	if (x>=y) return x;
	else return y;
}

int swap(int *x,int *y){
	int temp;
	temp=*x;
    *x=*y;
    *y=temp;
}

//�p��q�ڸ`�I�X�o���̤j�`�� 
int distance(int node)
{
	int depth;//�O���Ӯa�ڦ������`��
	int j;
    
    //�S���p�ġA���j���X�f����
    if(how_many[node]==0) 
        return 0;
    //�u���@�Ӥp�Įɨ�̤j�`�׬���p�ĳ̤j�`�צA�[ 1 
    else if(how_many[node]==1)
        for(int j=0;j<n-1;j++)
        {
        	if(CHILD[j][0]==node) 
			    return distance(CHILD[j][1])+1;
        }        
    //�h�Ӥp��
    else
    { 
	    /*
	      ���X�C�@�Ӥp�ġA��X�̤j�`�ת��e��W�A
	      �̤j�`���x�s��farthest1�A
	      �ĤG�j�`���x�s��farthest2
	    */ 
        int farthest1=0,farthest2=0;//�̤j�e��Ӫ��`��
        
        for(j=0;j<n-1;j++)
        {
            if(CHILD[j][0]==node)
            {
                depth=distance(CHILD[j][1])+1;
                if(depth>farthest1)
                    swap(&depth,&farthest1);
                if(depth>farthest2)
                    farthest2=depth;
            }
        }
        /*
		  �������`�I������פj�󵥩�2�A
		  �̤j��t�Z�����䤤��Ӥp�Ĥ�farthest1�P��farthest2�ۥ[�A 
		  �A�M����� answer �����j�� 
		*/ 
		answer = max(answer, farthest1 + farthest2);
        /*
		  �q�ڸ`�I�X�o�A�Y�a�ڪ�����
		  �^�ǸӮa�ڦ������̤j�`�� farthest1
		*/ 
        return farthest1;
    }
}
