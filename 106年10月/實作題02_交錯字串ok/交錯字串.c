#include <stdio.h>
#include <string.h>
#include <ctype.h>

int max(int x,int y) {
    if (x>=y) return x;
    else return y;
}

int main(void) {
    int k;
    printf("��J k ��(���): ");  //��J k ��(���) 
    scanf("%d", &k);
    char str[100000];
    printf("��J�r��: ");  //��J�r�� 
    scanf("%s", str);
	
	char capital_letter;  //�e�@�r���O�_���j�g,�p�G�O��Ȭ�'Y", �_�h��'N' 
	int Upper_no = 0;  //�s��j�g���r���`�� 
	int Lower_no = 0;  //�s��p�g���r���`��
	int Alternating_len = 0;  //�ثe������r����� 
	int longest = 0;  //�̪�������r�����,�Y���D�حn������ 
	
	//�B�z�Ĥ@�Ӧr�����@�k 
	if(islower(str[0])) { 
		capital_letter = 'N';  //�Ĥ@�Ӧr���O�j�g
		Lower_no = 1;  //�s��p�g��1
		if(k==1) {  
			Alternating_len = 1;
			longest = 1;
		}
	}
	else {  //�p�g�r��
		capital_letter = 'Y';  //�Ĥ@�Ӧr���O�j�g 
		Upper_no = 1;  //�s��j�g��1
		if(k==1) {
			Alternating_len = 1;
			longest = 1;
		}
	}	
	//��2�ӥH�᪺�r�����@�k 
	for(int i=1; i<strlen(str); i++) {
		if(islower(str[i]) && capital_letter=='N') {  //���r�����p�g�B�e�r���]�O�p�g 
			Lower_no += 1;  
			Upper_no = 0;  
			if(Lower_no==k) {  
				Alternating_len += k;  
				longest = max(Alternating_len, longest);  //���ظ��j�� 
			}
			if(Lower_no>k)  Alternating_len = k;  //�W�L�������C�J�p�� 
		}
		else if(islower(str[i]) && capital_letter=='Y') {  //���r�����p�g�B�e�r�����j�g 
			if(Upper_no<k)  Alternating_len = 0;  
			Lower_no = 1;  
			Upper_no = 0;  
			if(k==1) {  
				Alternating_len += k;  
				longest = max(Alternating_len, longest);
			}
			capital_letter = 'N';  //�]�w�e�@�r�����p�g 
		}
		else if(isupper(str[i]) && capital_letter=='Y') {  //���r�����j�g�B�e�r���]�O�j�g 
			Upper_no += 1;
			Lower_no = 0;
			if(Upper_no==k) {
				Alternating_len += k;
				longest = max(Alternating_len, longest);
			}
			if(Upper_no>k)  Alternating_len = k;
		}
		else if(isupper(str[i]) && capital_letter=='N') {  //���r�����j�g�B�e�r�����p�g 
			if(Lower_no<k)  Alternating_len = 0;
			Upper_no = 1;
			Lower_no = 0;
			if(Upper_no==k) {
				Alternating_len += k;
				longest = max(Alternating_len, longest);
			}
			capital_letter = 'Y';
		}
	}
	printf("%d\n", longest);

	return 0;
}
