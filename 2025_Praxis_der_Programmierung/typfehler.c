#include <stdio.h>
#include <stdlib.h>

int main() {
	float n;
	int rvalue;
    int c;
	
    while(1){
        printf("Geben Sie eine Zahl ein: ");
        rvalue = scanf("%f", &n);
        if (rvalue == 1){
            break;
        } else {
            printf("Fehler: Bitte geben Sie eine gueltige Zahl ein.\n");
            if (rvalue == 0) {
                do { 
                    c = getchar();
                } while (c != '\n'); 
            }
        }
    }
    printf("Die Zahl ist %f\n", n);
    return 0;
}
