#include <stdio.h>
#include <stdlib.h>
#define testdata "data1.txt"
#define SIZE 100000

void get_height(int); //取得每個節點的高度 
void print_root(int); //將找到的樹狀圖的根節點編號印出 
long total(int);  //函數原型宣告,回傳所有節點最大高度總和 

int parents[SIZE]={0}; //記錄每個節點父節點
int height[SIZE]={0}; //記錄每個節點的高度
int child_no[SIZE]={0}; //記錄每個節點的子節點數量

int main(void){  
    FILE *fp;
	int n; //節點的個數 
	int temp;
	long sum_of_height;
	
	fp=fopen(testdata,"r");
	fscanf(fp,"%d",&n); //從檔案中讀取樹狀圖的節點個數 
	for (int i=1; i<=n;i++){
		fscanf(fp,"%d",&child_no[i]); //讀取節點的編號 1 到 n的子節點個數 
		for (int j=1; j<=child_no[i];j++){
			fscanf(fp," %d",&temp); //依序每一個節點的子節點編號 
			parents[temp]=i; //記錄這些子節點的父節點編號 
		}
	}
	print_root(n);//輸出根節點的編號 
    get_height(n);//取得各節點的高度 
    sum_of_height=total(n);//計算各節點的高度總和 
    
    printf("%ld",sum_of_height);//輸出所有節點的高度總和 
    return 0;
}
//將找到的樹狀圖的根節點編號印出
void print_root(int n){
	for(int i=1;i<=n;i++){
		if(parents[i]==0)
		    printf("%d\n", i);
	}
}
//取得每個節點的高度
void get_height(int n){
	for(int i=1; i<=n;i++){
		if(child_no[i]==0){
			int tall=0; //記錄要計算節點的高度
			int node =parents[i]; //移動到 i 的父節點
			while (node!=0){
				tall++;
				if(tall>height[node]){
					height[node]=tall;
				} 
				node=parents[node];	 
		    }
		}
	}
} 
//回傳所有節點最大高度總和
long total(int n){
	long sum=0; //最大高度
	for(int i=1 ; i<=n ; i++){
    	sum = sum + height[i];
    }
	return sum;
}
