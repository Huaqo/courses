#include <stdio.h>

int main(void){
    int celsius_round;
    float celsius_exact;
    int fahrenheit=0;
    int max_fahrenheit = 300;
    int steps = 20;

    printf("\n\nFahrenheit \t Celsius(exakt) \t Celsius(gerundet) \n");

    while(fahrenheit <= max_fahrenheit){
        celsius_exact = (5.0/9.0) * (fahrenheit - 32.0);
        printf("%i \t\t %f \t\t\t %i \n", fahrenheit,  celsius_exact, (int)celsius_exact);
        fahrenheit+=steps;
    }
    
    return 0;
}
