#include <stdio.h>
#include <math.h>

int main() {
    int fahrenheit = 0; 
    int stepsize = 20;  
    int maxF = 300;     

    double celsius;

    printf("\n%s %s %s \n", "Fahrenheit","Celsius (gerundet)","Celsius (exakt)");

    while (fahrenheit <= maxF) {
        celsius = (5.0/9.0) * (fahrenheit - 32);
        printf("%d\t\t%d\t\t%f\n", fahrenheit, (int)celsius, celsius);
        fahrenheit += stepsize; 
    }

    return 0;
}

