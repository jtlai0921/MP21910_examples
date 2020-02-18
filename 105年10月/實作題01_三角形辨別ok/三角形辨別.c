#include <stdio.h>
#include <math.h>

void sort(int *a, int l) {
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

int main(void) {	
    int side[3];
  	 	
  	printf("請輸入三邊長: 例如: 3 4 5 \n");
  	scanf(" %d %d %d",&side[0],&side[1],&side[2]);
  	
  	/* 三邊長由小到大排序 */
  	sort(side,3);
  	/* 輸出由小到大排序的三邊長 */  	 	 
    printf("%d %d %d\n",side[0],side[1],side[2]);
    
  	if(side[0]+side[1]<=side[2])   //無法形成三角形 
    {
        printf("No");
        return 0;
    }
  		
    if(pow(side[0],2)+pow(side[1],2)<pow(side[2],2))				
        printf("Obtuse");
    else
        if(pow(side[0],2)+pow(side[1],2)!=pow(side[2],2))
            printf("Acute");
        else
            printf("Right");

    return 0;
}
