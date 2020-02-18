#include <stdio.h>

int main(void)
{
    int count = 10;
    if (count > 0) {
        count = 11;
    }
    if (count > 10) {
        count = 12;
        if (count % 3 == 4) {
            count = 1;
        }
        else {
            count = 0;
       }
    }
    else if (count > 11) {
        count = 13;
    }
    else {
        count = 14;
    }
    if (count) {
        count = 15;
    }
    else {
        count = 16;
    }
    printf ("%d\n", count);
 
    return 0;   
} 
