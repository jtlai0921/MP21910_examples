#include <stdio.h>
#define testdata "data1.txt"
const unsigned long SIZE=9999;
void line(char*,int,int);

int main(void) {
	int N;
	char part1[100000];
	char part2[100000];
	int start,end;
	int i;
	unsigned long j;
	unsigned long count;
	FILE *fp;
	
	fp=fopen(testdata,"r");
	fscanf(fp,"%d", &N);
	fscanf(fp,"%d %d", &start, &end);	
	
	line(part1,start,end);  //先取第一個線段資料 	
	for (i=1;i<=N-1;i++){	
	    fscanf(fp,"%d %d", &start, &end);
		line(part2,start,end); //取出下一個新線段	
		for ( j=0;j<SIZE;j++)//新線段與原線段進行OR運算 	
    		if (part1[j]=='Y' || part2[j]=='Y') 
			    part1[j]='Y';	
	}
	count=0; //計數器歸零 	
	int index=0;
	while (index<SIZE){
		if( part1[index]=='Y') { 
			count++; //累加被填滿的線段 
		} 
		index++;	
	}	
	printf("%d",count);
	fclose(fp);
	return 0;
}

void line(char segment[100000],int start,int end){ 
	unsigned long j;
	for (j=start ;j<end;j++) {
		/*從起始索引到結束索引之間的線段標示字元 Y */
		segment[j]='Y';
	}	 
}
