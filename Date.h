#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

class Date
{
private:
	int _day;
	int _month;
	int _year;

public:
	Date(int day, int month, int year);
	Date();
	Date(int day);
	Date(int day, int month);
	
	void ShowDate();
};


#endif // !_DATE_H_

