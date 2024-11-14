// rec_static.c

#include <stdio.h>

void rec_out(int n);
void decr(int n);


int main(){
   rec_out(6);
   return 0;
}


void decr(int n){
   rec_out(--n);
}


void rec_out(int n){
   static int count = 1;
   printf("Die %d. Ausgabe.\n", count);
   count++;
   if (n > 1){
      decr(n);
   }
}

