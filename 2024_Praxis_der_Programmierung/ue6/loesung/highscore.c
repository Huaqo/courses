//highscore.c

#include "highscore.h"
#include <stdio.h>

//define TEST
#if defined TEST
int main(){
    struct highscore hs;
    struct date datum = setInitDate(2077);
    int score = 9001;
    setHighscore(&hs, score, datum);
    printHighscore(&hs);

    return 0;
}

#endif

void setHighscore(struct highscore *hs, struct date datum, int newscore){
    hs->date = datum;
    hs->score = newscore;
}

void printHighscore(struct highscore * hs){
    printf(" Scores ab %d \n", firstYear);
    printf("your highscore: %d at date %d.%d.%d \n", hs->score, hs->date.day, hs->date.month, hs->date.year);
}