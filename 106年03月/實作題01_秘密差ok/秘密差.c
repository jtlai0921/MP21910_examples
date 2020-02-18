#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char X[1000];
    printf("叫块计ぃ禬筁1000タ俱计:  \n");  
    scanf("%s", X);
	
    int A = 0; //癘魁计计㎝ 
	int B = 0; //癘魁案计计㎝
    if (strlen(X) % 2!=0) {   //璝计羆ぃ砆2俱埃 ,ボ材じ琌计 
        for(int i=0; i<strlen(X); i++) { 
            if((i%2)==0)  A += (int)(X[i])-48; //计计羆 
            else  B += (int)(X[i])-48;  //案计计羆	
        } 
    }
    else{ //璝计羆砆2俱埃 ,ボ材じ琌案计 
        for(int i=0; i<strlen(X); i++){ 
            if((i%2)==0)  B += (int)(X[i])-48;  //案计计羆 
            else  A += (int)(X[i])-48;  //计计羆
        }		
    }
    printf("%d\n", abs(A-B));
    return 0;
}
