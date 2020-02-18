#include <stdio.h>
#include <math.h>
#define testdata "data1.txt"

//方向向量， 其中 0代表左 、1代表上 、2代表右 、3代表下
const int direction[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

int main()
{
    FILE *fp;
    int n;
    int row;
    int col;
    
    fp=fopen(testdata,"r");
    fscanf(fp,"%d", &n);  //輸入 第一行 是整數 N，N為奇數且不小於 3。 
    int dir; //用來記錄中間位置的起始方向
	/* 
	紀錄移動方式的變數, 一個 0~3 的整數 代表起始方向， 
	其中 0代表左 、1代表上 、2代表右 、3代表下 。 
	*/ 
    fscanf(fp,"%d", &dir); 
    int data[n][n]; //用來記錄陣列內容
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp,"%d", &data[i][j]);
   
    int step = 1; //用來控制同一個方向要持續走多少步
    int stepcounter = 0; //行進方向變化的計數器
    int counter = 1; //用來記錄已走訪的陣列元素個數
    row = floor(n / 2);
	col = floor(n / 2);
    printf("%d", data[row][col]);
    while (counter < n * n) {
        for (int i = 0; i < step; i++) {
            row += direction[dir][0];
            col += direction[dir][1];
            printf("%d", data[row][col]);
            counter++; 
            if (counter == n * n) break;  
        }
        stepcounter++;
        if (stepcounter % 2 == 0) step++;
        dir++;
        dir %= 4; //0,1,2,3移動方向四個一循環 
    }
    return 0;
}
