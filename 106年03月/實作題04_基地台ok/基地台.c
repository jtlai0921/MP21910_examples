#include <stdio.h>
#include <math.h>
#define testdata "data2.txt"

void mysort(int*,int); //mysort函式宣告,會將傳入陣列排序 
char isCovered(int); //isCovered函式宣告,回傳值為字元 

int N;  //服務點數目
int K;  //基地台數目
int P[50000];  //記錄服務點的距離資訊 

int main(void) {
    int lower_bound;
    int upper_bound;
	int med;
	FILE *fp;
    
    fp=fopen(testdata,"r");
    fscanf(fp,"%d%d", &N, &K);  //輸入服務點及基地台數目 
    for(int i=0; i<N; i++) {
        fscanf(fp,"%d", &P[i]); 
	}   
	//由小到大排序 
	mysort(P,N);
	//最小直徑為1，
	//最大直徑為floor((服務站最大座標-服務站最小座標)/基地台個數) + 1
    //答案介於這兩數之間，使用二分搜尋法找出答案。
	lower_bound = 1;  //最小值從1開始
	upper_bound = floor((P[N-1]-P[0])/K) + 1;  //其中floor函數功能是取比參數小的最大整數
	while(lower_bound <= upper_bound) {
		med = floor((lower_bound + upper_bound) / 2);  //二分搜尋法
		//如果傳回 'Y',表示傳入med直徑的大小符合條件,
		//接著將此傳入的直徑數值縮小後,再進行判斷 
		if(isCovered(med)=='Y')  
		    upper_bound = med;  
		//如果傳回 'N',表示傳入med直徑的大小不符合條件,
		//再接著將此傳入的直徑數值縮放大後,再進行判斷 
		else  
		    lower_bound = med + 1;  
		if(lower_bound == upper_bound)  
		    break;
	}
	printf("%d\n", med);
	return 0;
}

//自訂將mysort函式，傳入陣列的值由小到大排序後再回傳
void mysort(int *a, int l) {
    int i, j;
    int v;
    //開始排序 
    for(i = 0; i < l - 1; i ++)
        for(j = i+1; j < l; j ++)
        {
            if(a[i] > a[j])
            {
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        }
}

//自訂isCovered函式，測試所傳入的基地台直徑diameter參數，
//可否覆蓋所有據服務點，可以則回傳 'Y"，不可以則回傳'N"
char isCovered(int diameter) {  
	int coverage =0; //基地台覆蓋範圍 
	int number = 0; //基地台數量的計數器 
	int pos = 0;//服務點索引編號從 0 開始 
	
	for (int i=0;i<N;i++) //從最前面服務點開始找起 
	{
		coverage = P[pos] + diameter;  //基地台的覆蓋範圍
		number++;  //記錄基地台數目的計數器,此處要累加 1 
		/* 
		  如果基地台數量大於K,則傳回 'N',表示這個直徑大小
		  所涵蓋的範圍,無法完全覆蓋所有服務點 
		*/ 
		if(number>K)  
		    return 'N';
        //如果涵蓋全部服務點且基地台數量小於K則傳回 'Y' 
		if((number<=K) && (P[N-1]<=coverage) )  
		    return 'Y';  
		do{  //直接跳到下一個沒有被涵蓋的服務點
            pos++;
	    }while (P[pos]<=coverage);  
	}
}
