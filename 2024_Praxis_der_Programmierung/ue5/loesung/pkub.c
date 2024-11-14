
#include <stdio.h>
#include <stdlib.h>




int main(int argc, char * argv[]){
	if (argc == 2) {
		printf("bitte argument übergeben"); //argv ist programmname, 
		//argv[1] ist zhl daher 2 stk argc=2
	}
	else {
	double zahl = atof(argv[1]);  //covert to float
	printf("%s³ = %f\n", argv[1], zahl*zahl*zahl);
	}

	return 0;
}


