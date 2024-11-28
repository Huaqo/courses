#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "date.h"

typedef struct highscore {
    Date date;
    int score;
} Highscore;

void setHighscore(Highscore *highscore, int score, int year);

void prettyPrintHighscore(Highscore *highscore);

#endif