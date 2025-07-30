#include <stdio.h>

int main(){
    int i = 66;
    double x = .000007;
    double y = 123.45;
    printf("\ni:\n%d \n%o \n%x \n %X\n", i, i, i, i);
    printf("\nx:\n%f \n%e \n%E \n%g \n%G\n", x, x, x, x, x);
    printf("\ny:\n%g \n%G\n\n", y, y);
    return 0;
}