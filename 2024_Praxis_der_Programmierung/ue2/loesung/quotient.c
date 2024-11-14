#include <stdio.h>
#include <stdlib.h>

int y;

int f(int param1, int param2){
    if (param2 == 0) {
		printf("Fehler: Division durch %d nicht möglich \n", param2);
		exit(EXIT_FAILURE);
	}
	else {
		int res = (2*(param1*param1)) / param2;	
    	return res;
	}
}

int main(){
    int x = 4;
    while (1) {
		scanf("%d", &y);  // scanf erwartet Speicheradresse
		if (y != 0){
			break;
		}	
		else {
			printf("Fehler: Division durch 0 nicht möglich \n");
		}
}
    printf("%d \n",f(x,y));
}

