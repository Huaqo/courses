// highscore.h

#include "date.h"

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

int firstYear;

struct highscore{
    struct date date;
    int score;
};

void setHighscore(struct highscore * hs, struct date datum, int newscore);
void printHighscore(struct highscore * hs);

#endif