#include <stdio.h>

int main() {
    int a[8];
    int i;

    printf("Size of A: %lu\n", sizeof(a));

    printf("Array A:");

    for (i = 0; i < (sizeof (a)/4); i ++) {
        a[i] = 1;
        printf("%i",a[i]);
    }
    printf("\n");
}