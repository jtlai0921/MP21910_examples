#include <stdio.h>
#include <stdlib.h>
#define testdata "data2.txt"
#define X 10
#define Y 10
#define Z 10

/* 反向旋轉；將矩陣以逆時針方向轉90度 */ 
void rotate(int matrixA[X][Y], int *row, int *col){
	int matrixB[X][Y];
	int new_row=*col;
	int new_col=*row;
	int i,j;	
	for (i=1;i<=new_row;i++)
		for (j=1;j<=new_col;j++)
			matrixB[i][j]=matrixA[j][*col-i+1];
			
	for (i=1;i<X;i++)
		for (j=1;j<Y;j++)
			matrixA[i][j]=matrixB[i][j];
	*row=new_row;
	*col=new_col;
}
/* 翻轉 */ 
void flip(int matrixA[X][Y], int row, int col){
	int matrixB[X][Y];
	int i,j;
	for (i=1;i<=row;i++)
		for (j=1;j<=col;j++)
			matrixB[i][j]=matrixA[row-i+1][j];
			
	for (i=1;i<X;i++)
		for (j=1;j<Y;j++)
			matrixA[i][j]=matrixB[i][j];
}

int main(void) {
	FILE *fp;
	int i,j;
	int matrixA[X][Y];
	int action[Z];
	int row,col,m;
	
	fp=fopen(testdata,"r");
	fscanf(fp,"%d %d %d", &row,&col,&m);
	
	for (i=1;i<=row;i++)
		for (j=1;j<=col;j++)
			fscanf(fp,"%d ",&matrixA[i][j]);
	
	for (i=1;i<=m;i++)
		fscanf(fp,"%d", &action[i]);
				
	for (i=m;i>=1;i--){
		if (action[i]==0) rotate(matrixA,&row,&col); 
		else flip(matrixA,row,col); 
	}  
	
	printf("%d %d\n",row,col);
	for(i=1; i<=row; i++)  {
		for(j=1; j<=col; j++)
			printf("%d ",matrixA[i][j]);
		printf("\n");
  	}
  	
	fclose(fp);   
	return 0;
}
