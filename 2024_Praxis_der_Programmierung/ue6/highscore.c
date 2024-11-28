#include <stdio.h>
#include "date.h"
#include "highscore.h"

void setHighscore(Highscore *highscore, int score, int year){
    setDate(&highscore->date, year);
    highscore->score = score;
}

void prettyPrintHighscore(Highscore *highscore){
    printf("The Highscore on the %d.%d.%d is %d \n", highscore->date.day,highscore->date.month,highscore->date.year,highscore->score);
}
