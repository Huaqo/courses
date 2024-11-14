#include <stdio.h>
#define LEN 10


void rev_print(int * p){
    for (int i = LEN-1; i>= 0; i--){
	printf("%d ", *(p+i));
    }
    printf("\n");
}


int main (){
	int ar[LEN];
	for (int i = 1; i<=LEN; i++){
		ar[i-1] = i*i;
	}
	rev_print(ar);
}

