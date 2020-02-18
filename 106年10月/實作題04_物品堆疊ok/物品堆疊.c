#include <stdio.h>
#define testdata "data2.txt"

struct obj{  
  int w;  //���魫�q 
  int f;  //������Φ���
}; 

typedef struct obj OBJECT;

int main() {
    int N;  
   
    FILE *fp; 
    int min_energy_consumption = 0;  //�̤p���ӯ�q 
    int total = 0; //���~���q�`�M
	
	fp=fopen(testdata,"r");
    fscanf(fp,"%d", &N);   //�q�ɮ�Ū�����骺�Ӽ� 

    OBJECT obj[N]; 
	for(int i=0; i<N; i++)  //�q�ɮ�Ū�����~���q 
		fscanf(fp,"%d", &obj[i].w);
	for(int i=0; i<N; i++) //�q�ɮ�Ū�����~���Φ��� 
		fscanf(fp,"%d", &obj[i].f);

	/*
	�n�p��̤p���ӯ�q�������w�Ʀn���~������,�Ҧp��Ӫ��~obj[j]�� obj[j+1],
	�̨Ϊ����~�\�񶶧ǥ����H obj[j].w*obj[j+1].f < obj[j+1].w*obj[j].f�Ƨ�, 
	�]�N�O��,�Ӫ��~�V��(w)�B���Φ���(f)�V�p������b�U�h,
	���F�̨Ϊ����~���ǫ�,�N�i�H�p��̤p���ӯ�q 
	*/
	 
    OBJECT temp;
	for(int i=0; i<N-1; i++) {
		for(int j=0; j<N-1-i; j++) {
			if((obj[j].w*obj[j+1].f) > (obj[j+1].w*obj[j].f)) {
				temp = obj[j];
				obj[j] = obj[j+1];
				obj[j+1] = temp;
			}
		}
	}

	for(int i=0; i<N-1; i++) { //�@�h�@�h�p��U�h���~�����ӯ�q 
		total += obj[i].w;  //�֥[�e���U�h���~�����q
		min_energy_consumption += total * obj[i+1].f;//�p��̤p���ӯ�q 
	}		
		
	printf("%d\n", min_energy_consumption);
	
	return 0;
}
