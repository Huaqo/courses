#include <stdio.h>
#include <math.h>

int main() {
	int i;
	printf("\n");
	for (i=12; i>=0; i=i-2) {
		if (i==0){

			printf("%d \n", i);
		}
		else {
			printf("%d, ", i);
		}
	}

       	for (i=-1; i>=-13; i=i-2){
       		if (i==-13){
			printf("%d \n", i);
		}
		else {
			printf("%d, ", i);
		}
	}


	for (i=0; i<=9; i++){
		if (i == 9){
			printf("%d \n", (int)pow(i,(double)2));
		}
		else{
			printf("%d, ", (int)pow(i,(double)2));
		}
	}

    for (i=0; i<=9; i++){
        if (i==9){
            printf("%d \n", i*i);
        }
        else{
            printf("%d, ", i*i);
        }
    }

	return 0;
}

