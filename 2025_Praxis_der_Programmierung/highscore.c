#include <stdio.h>
#include "highscore.h"
#include "date.h"
	
Highscore createHighscore(Date date, int value){
	Highscore highscore = { .date = date, .value = value};
	return highscore;
}

void printHighscore(Highscore highscore){
	if (firstYear){
		printf("Scores ab: %d\n", firstYear);
	}
	printDate(highscore.date);
	printf(": %d\n", highscore.value);
}

#ifdef TEST_HIGHSCORE

int main(){

	Highscore highscore = createHighscore(createDate(1997),16);
	printHighscore(highscore);

}

#endif
