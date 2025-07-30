#ifndef DATE_H
#define DATE_H

typedef struct{
	int day;
	int month;
	int year;
} Date;

Date createDate(int year);
void printDate(Date date);

#endif // DATE_H
