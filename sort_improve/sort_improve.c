#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
#if 0
    int a = 10;
    printf("sizeof((a>5) ? 4 :8.0) = %d\n", sizeof((a>5) ? 4 :8.0));
    return 0;
#endif
#ifdef _SORT_IMPRVOE__
    char a = 1,b = 2,c;
    c = a + b;
    printf("c = %d\n", c);
    return 0;
#endif // DEBUG

#ifdef _SORT__
    int a;
    int* a;
    int** a;
    int a[10];
    int* a[10];
    int(*a)[10];
    int(*a)(int);
    int (*a[10])(int);
#endif
}

