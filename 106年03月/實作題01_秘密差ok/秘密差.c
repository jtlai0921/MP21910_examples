#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char X[1000];
    printf("�п�J��Ƥ��W�L1000�쪺�����:  \n");  
    scanf("%s", X);
	
    int A = 0; //�O���_�Ʀ�ƪ��M 
	int B = 0; //�O�����Ʀ�ƪ��M
    if (strlen(X) % 2!=0) {   //�Y�Ʀr�`���פ���Q2�㰣 ,��ܲĤ@�Ӧr���O�_��� 
        for(int i=0; i<strlen(X); i++) { 
            if((i%2)==0)  A += (int)(X[i])-48; //�_�Ʀ�Ʀr�[�` 
            else  B += (int)(X[i])-48;  //���Ʀ�Ʀr�[�`	
        } 
    }
    else{ //�Y�Ʀr�`���ׯ�Q2�㰣 ,��ܲĤ@�Ӧr���O����� 
        for(int i=0; i<strlen(X); i++){ 
            if((i%2)==0)  B += (int)(X[i])-48;  //���Ʀ�Ʀr�[�` 
            else  A += (int)(X[i])-48;  //�_�Ʀ�Ʀr�[�`
        }		
    }
    printf("%d\n", abs(A-B));
    return 0;
}
