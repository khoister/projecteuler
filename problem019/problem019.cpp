#include <iostream>
#include <vector>

static const int DAYS_IN_YEAR = (30 * 4) + (31 * 7) + 28;

typedef int Month;
static const Month JAN = 1;
static const Month FEB = 2;
static const Month MAR = 3;
static const Month APR = 4;
static const Month MAY = 5;
static const Month JUN = 6;
static const Month JUL = 7;
static const Month AUG = 8;
static const Month SEP = 9;
static const Month OCT = 10;
static const Month NOV = 11;
static const Month DEC = 12;


bool is_leap_year(int year)
{
	return ( (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0) ) ? true : false;
}

int days_in_year(int year)
{
	return (is_leap_year(year)) ? DAYS_IN_YEAR + 1 : DAYS_IN_YEAR;
}

int days_in_month(Month month, int year)
{
	switch (month)
	{
		case APR:
		case JUN:
		case SEP:
		case NOV:
			return 30;
		case FEB:
			return (is_leap_year(year) ? 29 : 28);
		default:
			break;
	}
	return 31;
}

int first_of_the_month(Month month, int year)
{
	int f = 0;

	if (month == JAN)
		f = 1;
	else
	{
		for (Month m = JAN; m < month; ++m)
			f += days_in_month(m, year);
		++f;
	}
	return f;
}

int main(int argc, char* argv[])
{
	int t = 0;
	int sunday = 1;
	for (int year = 1901; year < 2001; ++year)
	{
		for (Month month = JAN; month <= DEC; ++month)
		{
			int first = first_of_the_month(month, year);
			for (int day = sunday; day <= first; day+=7)
			{
				if (day == first)
					++t;

				sunday += 7;
			}
		}
		sunday -= days_in_year(year);
	}
	std::cout << t << std::endl;
	return 0;
}

