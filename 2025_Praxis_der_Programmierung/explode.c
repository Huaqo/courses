#include <stdio.h>

unsigned long long explode(unsigned int m, unsigned short n){
	return m << n;
}

int main(){
	unsigned int m = 3;
	unsigned short n = 4;
	unsigned long long x = explode(m, n);
	printf("%llu\n", x);
}
