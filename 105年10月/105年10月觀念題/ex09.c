#include <stdio.h>

int main(void)
{
    for(int s=100;s>=0;s--)
	{
	    printf("¤À¼Æ=%d µ¥¯Å=",s);
        if (s>=90) {
            printf ("A \n");
        }
        else if (s>=80) {
            printf ("B \n");
        }
        else if (s>60) {
            printf ("D \n");
        }
        else if (s>70) {
            printf ("C \n");
        }   
        else {
            printf ("F\n");
       }    	
    } 
    
    return 0; 
} 
