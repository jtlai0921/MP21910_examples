#include <stdio.h>

int G (int B) {
    printf ("�ۤv�[�J�ΨӰl�ܭȪ�B= %d \n", B);
    B = B * B;
    return B;
}

int main(void)
{
    int A=0, m=5;
    A = G(m);
    printf ("�ۤv�[�J�ΨӰl�ܭȪ�A= %d \n", A);
    if (m < 10) { 
        A = G(m) + A;
        printf ("�ۤv�[�J�ΨӰl�ܭȪ�A= %d \n", A);
    } 
    else
        A = G(m);

    printf ("���D�حn�l�ܪ��̲ת�A��= %d \n", A);
    return 0;
}
