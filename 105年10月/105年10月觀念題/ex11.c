#include <stdio.h>


int main(void)
{
    int maze[5][5]= {{1, 1, 1, 1, 1},
                 {1, 0, 1, 0, 1},
                 {1, 1, 0, 0, 1},
                 {1, 0, 0, 1, 1},
                 {1, 1, 1, 1, 1} };
    int count=0;
    for (int i=1; i<=3; i=i+1) {
        for (int j=1; j<=3; j=j+1) {
            int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
            for (int d=0; d<4; d=d+1) {
                if (maze[i+dir[d][0]][j+dir[d][1]]==1) {
                    count = count + 1;
                }
            }
        }
    }
    printf("%d",count);
    
    return 0; 
} 
