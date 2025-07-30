#include <stdio.h>
#define NL printf("\n");
#define LENGTH 1000

void writing_squarenumbers_array(int *array, int size){
    printf("Writing square numbers to Array...");
    for (int i = 0; i < size; i++){
        array[i] = i * i;
    }
    NL
}

int main(){
    int array[LENGTH];
    int input;
    writing_squarenumbers_array(array, LENGTH);
    
    while(1){
        printf("Geben Sie eine Zahl ein zwischen 1 und %d: \n", LENGTH);
        int result = scanf("%d", &input);

        if (result != 1){
            printf("Ungültige Eingabe. Bitte geben Sie eine ganze Zahl ein.\n");
            while (getchar() != '\n'); // Eingabepuffer leeren
            continue;
        }

        if (input == 0) {
            printf("Programm beendet.\n");
            break;
        }

        if (input < 1 || input > 1000) {
            printf("Fehler: Zahl außerhalb des gültigen Bereichs!\n");
            continue;
        }

        printf("Deine Quadratzahl ist: %d\n", array[input]);
        break;
    }

    return 0;

}