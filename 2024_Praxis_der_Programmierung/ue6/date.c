#include <stdio.h>
#include <stdlib.h>
#include "date.h"

void setDate(Date* date, int year){
    date->day = 1;
    date->month = 1;
    date->year = year; 
}

void prettyPrintDate(Date *date){
    printf("Day: %d Month: %d Year: %d \n", date->day,date->month,date->year);
}