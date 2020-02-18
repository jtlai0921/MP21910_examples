#include <stdio.h>

int main(void)
{
    int Total, Paid, Change;
    Total=162;
    Paid=1000;
    Change = Paid - Total;
    printf ("500 : %d pieces\n", (Change-Change%500)/500);
    Change = Change % 500;
    printf ("100 : %d coins\n", (Change-Change%100)/100);
    Change = Change % 100;
    // A °Ï
    printf ("50 : %d coins\n", (Change-Change%50)/50);
    Change = Change % 50;
    // B °Ï
    printf ("10 : %d coins\n", (Change-Change%10)/10);
    Change = Change % 10;
    // C °Ï
    printf ("5 : %d coins\n", (Change-Change%5)/5);
    Change = Change % 5;

    printf ("1 : %d coins\n", Change);
    return 0; 
} 
