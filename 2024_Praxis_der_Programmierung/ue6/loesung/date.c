//date.c

#include <stdio.h>
#include "date.h"

struct date setInitDate(int year){
    struct date d;
    d.year = year;
    d.month = 1;
    d.day = 1;
    return d;
}

void printDate(struct date * datum){
    printf("date: %d.%d.%d \n", datum->day, datum->month, datum->year);
}

