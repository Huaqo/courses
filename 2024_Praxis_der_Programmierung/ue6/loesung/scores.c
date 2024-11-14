#include "highscore.h"

int firstYear = 2000;

int main(){
    struct highscore hs;
    struct date datum = setInitDate(2077);
    int score = 9001;
    setHighscore(&hs, datum, score);
    printHighscore(&hs);

    return 0;
}