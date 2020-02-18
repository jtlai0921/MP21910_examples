#include <stdio.h>
void foo (int i);
void bar (int i);
void foo (int i) {
    if (i <= 5) {
        printf ("foo: %d\n", i);
    }
    else {
        bar(i - 10);
    }
}
void bar (int i) {
    if (i <= 10) {
        printf ("bar: %d\n", i);
    }
    else {
        foo(i - 5);
    }
}

int main(void)
{
    foo(15106);
    bar(3091);
    foo(6693);
 
    return 0;   
} 
