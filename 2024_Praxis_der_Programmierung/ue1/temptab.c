#include <stdio.h>

int main(void){
    int c_round;
    float c_exact;
    int f=0;
    int max_f = 300;
    int steps = 20;

    printf("Fahrenheit \t Celsius(gerundet) \t Celsius(exakt) \n");

    while(f <= max_f){
        c_exact = (5.0/9.0) * (f - 32.0);
        printf("%i \t\t %i \t\t\t %f \n", f, (int)c_exact, c_exact);
        f+=steps;
    }
    
    return 0;
}
