#include <stdio.h>
#define testdata "data2.txt"

struct obj{  
  int w;  //物體重量 
  int f;  //物體取用次數
}; 

typedef struct obj OBJECT;

int main() {
    int N;  
   
    FILE *fp; 
    int min_energy_consumption = 0;  //最小消耗能量 
    int total = 0; //物品重量總和
	
	fp=fopen(testdata,"r");
    fscanf(fp,"%d", &N);   //從檔案讀取物體的個數 

    OBJECT obj[N]; 
	for(int i=0; i<N; i++)  //從檔案讀取物品重量 
		fscanf(fp,"%d", &obj[i].w);
	for(int i=0; i<N; i++) //從檔案讀取物品取用次數 
		fscanf(fp,"%d", &obj[i].f);

	/*
	要計算最小消耗能量必須先安排好物品的順序,例如兩個物品obj[j]及 obj[j+1],
	最佳的物品擺放順序必須以 obj[j].w*obj[j+1].f < obj[j+1].w*obj[j].f排序, 
	也就是說,該物品越重(w)且取用次數(f)越小必須放在下層,
	有了最佳的物品順序後,就可以計算最小消耗能量 
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

	for(int i=0; i<N-1; i++) { //一層一層計算各層物品的消耗能量 
		total += obj[i].w;  //累加前面各層物品的重量
		min_energy_consumption += total * obj[i+1].f;//計算最小消耗能量 
	}		
		
	printf("%d\n", min_energy_consumption);
	
	return 0;
}
