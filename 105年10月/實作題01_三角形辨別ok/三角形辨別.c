#include <stdio.h>
#include <math.h>

void sort(int *a, int l) {
    int i, j;
    int v;
    //�}�l�Ƨ� 
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
  	 	
  	printf("�п�J�T���: �Ҧp: 3 4 5 \n");
  	scanf(" %d %d %d",&side[0],&side[1],&side[2]);
  	
  	/* �T����Ѥp��j�Ƨ� */
  	sort(side,3);
  	/* ��X�Ѥp��j�ƧǪ��T��� */  	 	 
    printf("%d %d %d\n",side[0],side[1],side[2]);
    
  	if(side[0]+side[1]<=side[2])   //�L�k�Φ��T���� 
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
