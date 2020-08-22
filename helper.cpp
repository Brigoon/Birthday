#include "helper.h"

void handleInput(char* argv[], BirthdayCalc& birthdayCalc_c)
{
	std::stringstream monthStr;
	std::stringstream dayStr;
	std::stringstream yearStr;
	int monthInt;
	int dayInt;
	int yearInt;

	monthStr << argv[1][0] << argv[1][1];
	dayStr << argv[1][3] << argv[1][4];
	yearStr << argv[1][6] << argv[1][7] << argv[1][8] << argv[1][9];

	monthStr >> monthInt;
	dayStr >> dayInt;
	yearStr >> yearInt;

	birthdayCalc_c.setMonth(monthInt);
	birthdayCalc_c.setDay(dayInt);
	birthdayCalc_c.setYear(yearInt);
}

BirthdayCalc::BirthdayCalc() :m_month_i32(0), m_day_i32(0), m_year_i32(0) {}

int BirthdayCalc::getMonth()
{
	return m_month_i32;
}
int BirthdayCalc::getDay()
{
	return m_day_i32;
}
int BirthdayCalc::getYear()
{
	return m_year_i32;
}

void BirthdayCalc::setMonth(int num)
{
	m_month_i32 = num;
}
void BirthdayCalc::setDay(int num)
{
	m_day_i32 = num;
}
void BirthdayCalc::setYear(int num)
{
	m_year_i32 = num;
}

void BirthdayCalc::printDate()
{
	std::cout << m_month_i32 << "/";
	std::cout << m_day_i32 << "/";
	std::cout << m_year_i32 << std::endl;
}