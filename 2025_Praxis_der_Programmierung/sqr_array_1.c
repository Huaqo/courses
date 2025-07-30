#include <stdio.h>
#define NL printf("\n");
#define ARROWS 3
#define ARCOLUMNS 4
int main()
{
    int ar[ARROWS][ARCOLUMNS] = {
        {0, 1, 2, 3},
        {10, 11, 12},
        {0}
    };
    
    for (int i = 0; i < ARROWS; i++){
        for (int j = 0; j < ARCOLUMNS; j++){
            printf("%d\t", ar[i][j]);
        }
        NL
    }
}
