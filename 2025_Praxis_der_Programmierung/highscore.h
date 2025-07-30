#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "date.h"

int firstYear;

typedef struct {
	Date date;
	int value;
} Highscore;

Highscore createHighscore(Date date, int value);

void printHighscore(Highscore highscore);

#endif //HIGHSCORE_H

