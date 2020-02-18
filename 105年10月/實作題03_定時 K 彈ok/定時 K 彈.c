#include <stdio.h>

struct node {
	unsigned long no;
	unsigned long next;
};

typedef struct node player;
player person[200000];

int main(void) {	
	unsigned long N; //N個人玩遊戲 
	unsigned long M; //傳到第M個人就會爆炸 
	unsigned long K; //炸彈只會爆炸K次 
	unsigned long bomb; //用來累計爆炸次數的變數
	int i;

	
	printf("請輸入n m k三變數的值,中間以空白隔開: \n"); 
	scanf("%d %d %d", &N, &M, &K);	
	//建立環狀鏈結串列 
	for (i=0 ;i<N-1;i++){
		person[i].no=i+1;  
		person[i].next=i+1;
	}
	person[N-1].no=N;  
	person[N-1].next=0; //串列尾指向串列頭形成一個環狀鏈結串列
	
	unsigned long count=0; //記錄炸彈傳到第幾人的計數器 
	unsigned long current=0; //目前炸彈傳到哪一位玩家的索引值 
	unsigned long pre=0; //前一位拿炸彈玩家的索引值 
	bomb=0;  //紀錄爆炸次數的變數,並事先歸零 
	while(bomb<K){
		count=count+1;	//計數器 
		if (count==M){			
			//從環狀串列中刪除這個號碼的位置 
			person[pre].next=person[current].next;  
			count=0;  //計數器歸零
			N=N-1;	//剩下玩遊戲的人的總數少1 
			bomb++;//爆炸次數累加1 
		} 
		pre=current;
		current=person[current].next;
	}
	printf("%d\n",person[current].no);			
	return 0;
}
