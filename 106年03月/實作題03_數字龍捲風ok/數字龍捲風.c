#include <stdio.h>
#include <math.h>
#define testdata "data1.txt"

//��V�V�q�A �䤤 0�N�� �B1�N��W �B2�N��k �B3�N��U
const int direction[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

int main()
{
    FILE *fp;
    int n;
    int row;
    int col;
    
    fp=fopen(testdata,"r");
    fscanf(fp,"%d", &n);  //��J �Ĥ@�� �O��� N�AN���_�ƥB���p�� 3�C 
    int dir; //�ΨӰO��������m���_�l��V
	/* 
	�������ʤ覡���ܼ�, �@�� 0~3 ����� �N��_�l��V�A 
	�䤤 0�N�� �B1�N��W �B2�N��k �B3�N��U �C 
	*/ 
    fscanf(fp,"%d", &dir); 
    int data[n][n]; //�ΨӰO���}�C���e
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp,"%d", &data[i][j]);
   
    int step = 1; //�Ψӱ���P�@�Ӥ�V�n���򨫦h�֨B
    int stepcounter = 0; //��i��V�ܤƪ��p�ƾ�
    int counter = 1; //�ΨӰO���w���X���}�C�����Ӽ�
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
        dir %= 4; //0,1,2,3���ʤ�V�|�Ӥ@�`�� 
    }
    return 0;
}
