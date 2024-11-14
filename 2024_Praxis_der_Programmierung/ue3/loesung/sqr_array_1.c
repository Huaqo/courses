#include <stdio.h>
#define LEN 10

int main (){
	int ar[LEN];
	for (int i = 1; i<=LEN; i++){
		ar[i-1] = i*i;
		printf("%d ",ar[i-1]);
	}
	printf("\n");
}

