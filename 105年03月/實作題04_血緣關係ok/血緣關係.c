#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#define testdata "data1.txt"

int distance(int); //函數原型宣告 
int max(int,int);  //函數原型宣告
int swap(int *,int *); //函數原型宣告

int CHILD[10000][2]; //記錄每位成員的小孩情況 
int answer=0; //最終答案, 記錄最長血緣距離 
int how_many[10000]={0}; //記錄每位成員有多少小孩 
char other_child[10000]={0}; //判斷是否為其他人的小孩 
int n;  //家庭成員人數 

int main(void) {
    FILE *fp; 
    int i;
    int root;  //家族的根節點,即祖先 
    int from_root;   //紀錄從根節點出發的最大深度 
    
    //從外部檔案讀取資料 
    fp=fopen(testdata,"r");
    fscanf(fp,"%d",&n);  //讀取家族成員總數 
    //逐行讀取各成員的小孩資訊 
	for(i=0;i<n-1;i++) {
    	fscanf(fp,"%d %d",&CHILD[i][0],&CHILD[i][1]); 
    	how_many[CHILD[i][0]]+=1; 
    	other_child[CHILD[i][1]]=1; //為他人小孩就記錄為 1 
	}
	//找出樹狀圖的根節點,即祖先
    for (i=0;i<n;i++) {  
		if (other_child[i]==0) {
			root =i ;
			break;
		}
    }
	from_root=distance(root); //從根節點出發的最大深度 
	answer=max(from_root,answer);
	printf("%d", answer);
	
	return 0;
}

//傳回兩數間較大值 
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

//計算從根節點出發的最大深度 
int distance(int node)
{
	int depth;//記錄該家族成員的深度
	int j;
    
    //沒有小孩，遞迴的出口條件
    if(how_many[node]==0) 
        return 0;
    //只有一個小孩時其最大深度為其小孩最大深度再加 1 
    else if(how_many[node]==1)
        for(int j=0;j<n-1;j++)
        {
        	if(CHILD[j][0]==node) 
			    return distance(CHILD[j][1])+1;
        }        
    //多個小孩
    else
    { 
	    /*
	      走訪每一個小孩，找出最大深度的前兩名，
	      最大深度儲存到farthest1，
	      第二大深度儲存到farthest2
	    */ 
        int farthest1=0,farthest2=0;//最大前兩個的深度
        
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
		  中間的節點的分支度大於等於2，
		  最大血緣距離為其中兩個小孩中farthest1與第farthest2相加， 
		  再和原先的 answer 取較大值 
		*/ 
		answer = max(answer, farthest1 + farthest2);
        /*
		  從根節點出發，即家族的祖先
		  回傳該家族成員的最大深度 farthest1
		*/ 
        return farthest1;
    }
}
