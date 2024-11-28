#ifndef DATE_H
#define DATE_H

typedef struct date{
    int day;
    int month;
    int year;
} Date;

void setDate(Date *date, int year);

void prettyPrintDate(Date *date);

#endif