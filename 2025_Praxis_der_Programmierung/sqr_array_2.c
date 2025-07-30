#include <stdio.h>
#define NL printf("\n");
#define LENGTH 10


void writing_squarenumbers_array(int *array, int size){
    printf("Writing square numbers to Array...");
    for (int i = 0; i < size; i++){
        array[i] = i * i;
    }
    NL
}


void print_array(int *array, int size){
    printf("Printing Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    NL
}


void print_array_rev(int *array, int size){
    printf("Printing Array (reversed): ");
    for (int i = 0; i < size; i++){
        printf("%d ", array[size - 1 - i]);
    }
    NL
}


int main(){
    int array[LENGTH];
    writing_squarenumbers_array(array, LENGTH);
    print_array(array, LENGTH);
    print_array_rev(array, LENGTH);
}