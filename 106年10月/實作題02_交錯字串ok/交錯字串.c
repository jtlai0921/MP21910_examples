#include <stdio.h>
#include <string.h>
#include <ctype.h>

int max(int x,int y) {
    if (x>=y) return x;
    else return y;
}

int main(void) {
    int k;
    printf("輸入 k 值(整數): ");  //輸入 k 值(整數) 
    scanf("%d", &k);
    char str[100000];
    printf("輸入字串: ");  //輸入字串 
    scanf("%s", str);
	
	char capital_letter;  //前一字元是否為大寫,如果是其值為'Y", 否則為'N' 
	int Upper_no = 0;  //連續大寫的字元總數 
	int Lower_no = 0;  //連續小寫的字元總數
	int Alternating_len = 0;  //目前交錯的字串長度 
	int longest = 0;  //最長交錯的字串長度,即本題目要的答案 
	
	//處理第一個字元的作法 
	if(islower(str[0])) { 
		capital_letter = 'N';  //第一個字元是大寫
		Lower_no = 1;  //連續小寫為1
		if(k==1) {  
			Alternating_len = 1;
			longest = 1;
		}
	}
	else {  //小寫字母
		capital_letter = 'Y';  //第一個字元是大寫 
		Upper_no = 1;  //連續大寫為1
		if(k==1) {
			Alternating_len = 1;
			longest = 1;
		}
	}	
	//第2個以後的字元的作法 
	for(int i=1; i<strlen(str); i++) {
		if(islower(str[i]) && capital_letter=='N') {  //此字元為小寫且前字元也是小寫 
			Lower_no += 1;  
			Upper_no = 0;  
			if(Lower_no==k) {  
				Alternating_len += k;  
				longest = max(Alternating_len, longest);  //取目較大值 
			}
			if(Lower_no>k)  Alternating_len = k;  //超過部分不列入計算 
		}
		else if(islower(str[i]) && capital_letter=='Y') {  //此字元為小寫且前字元為大寫 
			if(Upper_no<k)  Alternating_len = 0;  
			Lower_no = 1;  
			Upper_no = 0;  
			if(k==1) {  
				Alternating_len += k;  
				longest = max(Alternating_len, longest);
			}
			capital_letter = 'N';  //設定前一字元為小寫 
		}
		else if(isupper(str[i]) && capital_letter=='Y') {  //此字元為大寫且前字元也是大寫 
			Upper_no += 1;
			Lower_no = 0;
			if(Upper_no==k) {
				Alternating_len += k;
				longest = max(Alternating_len, longest);
			}
			if(Upper_no>k)  Alternating_len = k;
		}
		else if(isupper(str[i]) && capital_letter=='N') {  //此字元為大寫且前字元為小寫 
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
