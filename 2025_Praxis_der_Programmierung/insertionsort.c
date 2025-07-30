#include <stdio.h>

#define seperator printf("-----------------------\n")

void insertionSort(int arr[], int len){
    int i, val, pos;
    for(i = 0; i < len; i++) {
        val = arr[i];
        pos = i;
        while((pos > 0) && (arr[pos - 1] > val)){
            arr[pos] = arr[pos - 1];
            pos = pos - 1;
        }
        if (pos != i)
            arr[pos] = val;
    }
}

void prettyprint(int arr[],int len){
    int i;
    if (len == 0){
        printf("leer\n");
        return;
    }
    for(i=0;i<len-1;i++) {
        printf("%d, ",arr[i]);
    }
    printf("%d\n",arr[len-1]);
}

int main() {
     int a1[] = {3,2,1,3,4,5,3,7,6,8,3};
     int a2[] = {1};
     int a3[] = {1,2,3,4};
     int a4[] = {4,3,2,1};
     int a5[] = {};

     prettyprint(a1,11);
     insertionSort(a1,11);
     prettyprint(a1,11);
     seperator;

     prettyprint(a2,1);
     insertionSort(a2,1);
     prettyprint(a2,1);
     seperator;

     prettyprint(a3,4);
     insertionSort(a3,4);
     prettyprint(a3,4);
     seperator;

     prettyprint(a4,4);
     insertionSort(a4,4);
     prettyprint(a4,4);
     seperator;

     prettyprint(a5,0);
     insertionSort(a5,0);
     prettyprint(a5,0);
     printf("\n");

     return 0;
}
