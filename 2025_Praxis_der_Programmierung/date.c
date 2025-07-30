#include <stdio.h>
#include "date.h"

Date createDate(int year){
	Date date = {.day = 1, .month = 1, .year = year};
	return date;
}

void printDate(Date date){
	printf("%d.%d.%d", date.day, date.month, date.year);
}
