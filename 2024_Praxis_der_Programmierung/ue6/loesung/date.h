// date.h

#ifndef DATE_H
#define DATE_H

struct date{
    int day, month, year;
};

struct date setInitDate(int year);
void printDate(struct date *d);

#endif
