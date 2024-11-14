
#include <stdio.h>


unsigned long long explode(unsigned int m, unsigned short n);

int main(){
    printf("2* 2^n: %llu", explode(2,3));
}

unsigned long long explode(unsigned int m, unsigned short n){
    return m << n;  // n mal nach links shiften m*2^n
}

struct Node {
int data;
struct Node *next;
};
