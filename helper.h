#include <iostream>
#include <sstream>

class BirthdayCalc
{
public:
	BirthdayCalc();

	int getMonth();
	int getDay();
	int getYear();

	void setMonth(int num);
	void setDay(int num);
	void setYear(int num);

	void printDate();

private:
	int m_month_i32;
	int m_day_i32;
	int m_year_i32;
};

void handleInput(char* argv[], BirthdayCalc &birthdayCalc_c);