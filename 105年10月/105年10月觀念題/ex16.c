#include <stdio.h>

void G ( int* a_ptr, int** a_ptrptr) {

}

int main(void)
{
    int a = 1;
    // �[�J a_ptr, a_ptrptr �ܼƪ��ŧi
    int* a_ptr;
    int** a_ptrptr;
    a_ptr = &a;
    a_ptrptr = &a_ptr;
    G (a_ptr, a_ptrptr);

    printf ("%d  %d", *a_ptr, **a_ptrptr);

    return 0; 
} 
