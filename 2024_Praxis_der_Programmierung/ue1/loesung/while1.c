#include <stdio.h>
#include <math.h>

int main(){
	int i;

	printf("\n");
	
	i=12;
	while(i>=0){
		if (i==0){

                        printf("%d \n", i);
                }
                else {
                        printf("%d, ", i);
                }
	i=i-2;	
	}

	i=-1;
	do{
		if (i==-13){
                        printf("%d \n", i);
                }
                else {
                        printf("%d, ", i);
                }
		i=i-2;
	}
	while(i>=-13);

    i=0;
    while(i<=9){
        if (i==9){
            printf("%d \n", i*i);
        }
        else{
    		printf("%d, ", i*i);
        }
        i++;
    }

	return 0;
}
