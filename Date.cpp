#include "Date.h"

Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year) {}
Date::Date() : Date(1, 1, 1900) {}
Date::Date(int day) : Date(day, 1, 1900) {}
Date::Date(int day, int month) : Date(day, month, 1900) {}

void Date::ShowDate()
{
	std::cout << _day << '.' << _month << '.' << _year << ' ';
}