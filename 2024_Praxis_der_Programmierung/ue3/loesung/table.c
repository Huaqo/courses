#include <stdio.h>
#define zv printf("\n")

int main(){
    int ar[3][4] = {{0, 1, 2, 3}, {10, 11, 12}};

    int len_ar = (int) sizeof(ar)/sizeof(int);
    int col = (int) sizeof(ar[0])/sizeof(int);
    int row = len_ar/col;
	
    for (int i = 0; i<row; i++){
        for (int j = 0; j<col; j++){
            printf("%d \t", ar[i][j]);
	    }
	zv;
    }
    return 0;  
}
