#include <stdio.h>
#define LEN 1000

int main (){
	int ar[LEN];

	for (int i = 0; i<=LEN; ++i){
		ar[i] = i*i;
	}
	
	int input;
	printf("Geben Sie eine ganze Zahl zwischen 1 und %d an: ", LEN);
	
	while (1){
		scanf("%d", &input);
		printf("%d \n",input);

		if (input == 0){
		    break;
		}
		if (input < 1 || input > LEN){
		    continue;
		}

		else{
			printf("%d \n", ar[input]);
		}
	}
}

