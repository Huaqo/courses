#include <stdio.h>
#include <stdlib.h>
#include "date.h"
#include "highscore.h"

int main(){

    int year1 = 2024;
    int score1 = 10;

    Highscore highscore;
    setHighscore(&highscore, score1, year1);
    prettyPrintHighscore(&highscore);

}