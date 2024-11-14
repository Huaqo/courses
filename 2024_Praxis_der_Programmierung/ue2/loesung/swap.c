#include <stdio.h>

void swap(int *a1, int *a2){
	int s = *a1;
	*a1 = *a2;
	*a2 = s;
}
-
int main() {
	int var1 = 4;
	int var2 = 5;
	printf("var1: %d, var2: %d \n", var1, var2);
	swap(&var1, &var2);
	printf("swapped var1: %d, swapped var2: %d \n", var1, var2);
}
