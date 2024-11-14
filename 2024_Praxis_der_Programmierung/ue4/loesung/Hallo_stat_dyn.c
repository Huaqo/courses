#include <stdio.h>

int main() {

char *statS = "Hallo PdP";
char dynS[10] = "Hallo PdP";  

printf("stat Buchstabe an 2. Stelle: %c \n", dynS[1]);
printf("dyn. Buchstabe an 2. Stelle: %c \n", statS[1]);

//dynS[1] = 'e';
//printf("dyn Buchstabe an 2. Stelle verändert: %c \n", dynS[1]);

//statS[1] = 'e';
//printf("stat Buchstabe an 2. Stelle verändert: %c \n", statS[1]);

statS = "neuer String";
printf("stat Buchstabe an 2. Stelle verändert: %c \n", statS[1]);

dynS = "neuer String";
printf("dyn. Buchstabe an 2. Stelle verändert: %c \n", dynS[1]);

return 0;

}
