#include <stdio.h>

struct node {
	unsigned long no;
	unsigned long next;
};

typedef struct node player;
player person[200000];

int main(void) {	
	unsigned long N; //N�ӤH���C�� 
	unsigned long M; //�Ǩ��M�ӤH�N�|�z�� 
	unsigned long K; //���u�u�|�z��K�� 
	unsigned long bomb; //�ΨӲ֭p�z�����ƪ��ܼ�
	int i;

	
	printf("�п�Jn m k�T�ܼƪ���,�����H�ťչj�}: \n"); 
	scanf("%d %d %d", &N, &M, &K);	
	//�إ������쵲��C 
	for (i=0 ;i<N-1;i++){
		person[i].no=i+1;  
		person[i].next=i+1;
	}
	person[N-1].no=N;  
	person[N-1].next=0; //��C�����V��C�Y�Φ��@�������쵲��C
	
	unsigned long count=0; //�O�����u�Ǩ�ĴX�H���p�ƾ� 
	unsigned long current=0; //�ثe���u�Ǩ���@�쪱�a�����ޭ� 
	unsigned long pre=0; //�e�@�쮳���u���a�����ޭ� 
	bomb=0;  //�����z�����ƪ��ܼ�,�èƥ��k�s 
	while(bomb<K){
		count=count+1;	//�p�ƾ� 
		if (count==M){			
			//�q������C���R���o�Ӹ��X����m 
			person[pre].next=person[current].next;  
			count=0;  //�p�ƾ��k�s
			N=N-1;	//�ѤU���C�����H���`�Ƥ�1 
			bomb++;//�z�����Ʋ֥[1 
		} 
		pre=current;
		current=person[current].next;
	}
	printf("%d\n",person[current].no);			
	return 0;
}
