#include <stdio.h>
#include <stdlib.h>

int y;

int func(int a, int b){
    if (b == 0){
        return -1;
    }
    else {
        return (2 * (a * a)) / b;
    }
}

int main (void){
    
    int x = 4;
    
    printf("Geben Sie eine ganze Zahl ein: ");
    scanf("%i", &y);

    int result = func(x,y);
    
    if(result == -1){
        printf("Ein Fehler ist aufgetreten.\n");
    } else {
        printf("Berechneter Wert: %i\n", result);
    }

    for(int i = 0; i <= 30; i++){
        y = i;
        result = func(x,y);
        if(result == -1){
            printf("Ein Fehler ist aufgetreten.\n");
        } else {
            printf("x: %i, y: %i, z: %i\n", x,y, result);
        }
    }
}
