#include "helper.h"

namespace BirthdaysAreFun
{

	void handleInput(char* argv[], BirthdayCalc& birthdayCalc)
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

		birthdayCalc.setMonth(monthInt);
		birthdayCalc.setDay(dayInt);
		birthdayCalc.setYear(yearInt);
	}

	void calcDayOfWeek(BirthdayCalc& birthdayCalc)
	{
		int daysUpToYear = calcDaysUpToYear(birthdayCalc);
		int daysUpToMonth = calcDaysUpToMonth(birthdayCalc);

		int totalDays = daysUpToYear + daysUpToMonth + birthdayCalc.getDay();

		finalDayOfTheWeek(birthdayCalc, totalDays);
	}

	int calcDaysUpToYear(BirthdayCalc& birthdayCalc_c)
	{
		int years = birthdayCalc_c.getYear() - 1;
		int totalDays = years * daysPerYear;
		int leapDays = (birthdayCalc_c.getYear() / leapYearNum) 
			- (birthdayCalc_c.getYear() / dumbLeapYearNum);
		totalDays += leapDays;

		return totalDays;
	}

	int calcDaysUpToMonth(BirthdayCalc& birthdayCalc_c)
	{
		int totalDays = 0;

		switch (birthdayCalc_c.getMonth())
		{
			case 1:
			{
				totalDays += 31;
			}
			case 2:
			{
				if ((birthdayCalc_c.getYear() % leapYearNum == 0) &&
					(birthdayCalc_c.getYear() % dumbLeapYearNum != 0))
				{
					totalDays += 29;
				}
				else
				{
					totalDays += 28;
				}
			}
			case 3:
			{
				totalDays += 31;
			}
			case 4:
			{
				totalDays += 30;
			}
			case 5:
			{
				totalDays += 31;
			}
			case 6:
			{
				totalDays += 30;
			}
			case 7:
			{
				totalDays += 31;
			}
			case 8:
			{
				totalDays += 31;
			}
			case 9:
			{
				totalDays += 30;
			}
			case 10:
			{
				totalDays += 31;
			}
			case 11:
			{
				totalDays += 30;
			}
			case 12:
			{
				totalDays += 31;
			}
		}

		return totalDays;
	}

	void finalDayOfTheWeek(BirthdayCalc& birthdayCalc_c, int totalDays)
	{
		int dayOfWeek_i32 = totalDays % daysPerWeek;
		
		switch (dayOfWeek_i32)
		{
			case 0:
			{
				birthdayCalc_c.setDayOfWeek("Sunday");
				break;
			}
			case 1:
			{
				birthdayCalc_c.setDayOfWeek("Monday");
				break;
			}
			case 2:
			{
				birthdayCalc_c.setDayOfWeek("Tuesday");
				break;
			}
			case 3:
			{
				birthdayCalc_c.setDayOfWeek("Wednesday");
				break;
			}
			case 4:
			{
				birthdayCalc_c.setDayOfWeek("Thursday");
				break;
			}
			case 5:
			{
				birthdayCalc_c.setDayOfWeek("Friday");
				break;
			}
			case 6:
			{
				birthdayCalc_c.setDayOfWeek("Saturday");
				break;
			}
		}
	}

	void outputAnswer(BirthdayCalc& birthdayCalc)
	{
		std::cout << birthdayCalc.getDayOfWeek() << std::endl;
	}

	BirthdayCalc::BirthdayCalc() :m_month_i32(0), m_day_i32(0), m_year_i32(0), m_dayOfWeek_str("") {}

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
	std::string BirthdayCalc::getDayOfWeek()
	{
		return m_dayOfWeek_str;
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
	void BirthdayCalc::setDayOfWeek(std::string str)
	{
		m_dayOfWeek_str = str;
	}

	void BirthdayCalc::printDate()
	{
		std::cout << m_month_i32 << "/";
		std::cout << m_day_i32 << "/";
		std::cout << m_year_i32 << std::endl;
	}
}