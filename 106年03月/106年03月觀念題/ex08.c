#include <stdio.h>

int s = 1; // �����ܼ�
void add (int a) {
    int s = 6;  //�ϰ��ܼ�,���Ľd��u�b��Ƥ� 
    for( ; a>=0; a=a-1) {
        printf("%d,", s);
        s++;
        printf("%d,", s);
    }
}

int main(void)
{
    printf("%d,", s);
    add(s);
    printf("%d,", s);
    s = 9;
    printf("%d", s);
    return 0;
} 
