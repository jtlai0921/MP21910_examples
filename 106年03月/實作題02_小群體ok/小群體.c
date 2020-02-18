#include <stdio.h>

int main(void) {
	int no[50000];
	int marked[50000];
	int i,n;
	int num; //多少個小群體的計數器 
	
	scanf("%d",&n); //讀取團體人數 
	for (i=0;i<=n-1;i++){		
		scanf("%d",&no[i]); //從0到N依序讀取各好友編號 
		marked[i]=0;//初值設定每一個編號都尚未拜訪 
	}
	i=0;  
	num=0;//歸零 
	int find=0; //如果還沒找到小群體預設值為0 
	int head;
	while (find==0) { 
		head=i;//紀錄每一個小群體的頭 	
		while (no[i]!=head && marked[i]==0 ){
			marked[i]=1; //設定已探訪
			i=no[i];	//繼續探訪他的好友		
		}
		num++;	//累加有多少個小群體
		marked[i]=1;	 //設定已探訪	
		find=1;  //表示已順利找到小群體
		//依序找出不在已找到的群體中且沒有探訪者，從該編號開始探訪 
		for (i=0 ;i<=n-1;i++)
			if (marked[i]==0){
				find=0;
				break;
			}
	}
	printf("%d",num);
	return 0;
}
