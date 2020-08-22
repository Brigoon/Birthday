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

		// Need to subtract 1 since Day 0 is 01/01/2000 (as opposed to Day 1).
		int totalDays = daysUpToYear + daysUpToMonth + birthdayCalc.getDay() - 1;

		finalDayOfTheWeek(birthdayCalc, totalDays);
	}

	int calcDaysUpToYear(BirthdayCalc& birthdayCalc_c)
	{
		// Setting everything to 2000 as reference.
		int yearsToCount = birthdayCalc_c.getYear() - 2000;

		// Finding how many days to account for leap years
		// for the 4 year pattern.
		int leapDays = yearsToCount / leapYearNum;

		// Subtracting days caused by the 100 year pattern.
		leapDays -= yearsToCount / dumbLeapYearNum;

		// Adding days caused by the 400 year pattern.
		leapDays += yearsToCount / extraDumbLeapYearNum;

		// Have to count 2000 as a leap year. When it is a leap year,
		// yearsToCount will be divisible by 4 so we don't want to add.
		if (yearsToCount > 0 && !birthdayCalc_c.isLeapYear())
			++leapDays;

		return (yearsToCount * 365) + leapDays;
	}

	int calcDaysUpToMonth(BirthdayCalc& birthdayCalc_c)
	{
		int totalDays = 0;

		// Simply count the days from the beginning of the year
		// to the end of the month before the specified month.
		switch (birthdayCalc_c.getMonth())
		{
			case 1:
			{
				break;
			}
			case 2:
			{
				totalDays = DaysPerMonth::JANUARY;
				break;
			}
			case 3:
			{
				totalDays = DaysPerMonth::FEBRUARY;
				break;
			}
			case 4:
			{
				totalDays = DaysPerMonth::MARCH;
				break;
			}
			case 5:
			{
				totalDays = DaysPerMonth::APRIL;
				break;
			}
			case 6:
			{
				totalDays = DaysPerMonth::MAY;
				break;
			}
			case 7:
			{
				totalDays = DaysPerMonth::JUNE;
				break;
			}
			case 8:
			{
				totalDays = DaysPerMonth::JULY;
				break;
			}
			case 9:
			{
				totalDays = DaysPerMonth::AUGUST;
				break;
			}
			case 10:
			{
				totalDays = DaysPerMonth::SEPTEMBER;
				break;
			}
			case 11:
			{
				totalDays = DaysPerMonth::OCTOBER;
				break;
			}
			case 12:
			{
				totalDays = DaysPerMonth::NOVEMBER;
				break;
			}
		}

		// Determine if we need to add a day for leap year.
		if (birthdayCalc_c.isLeapYear() && birthdayCalc_c.getMonth() > 2)
		{
			totalDays += 1;
		}

		return totalDays;
	}

	void finalDayOfTheWeek(BirthdayCalc& birthdayCalc_c, int totalDays)
	{
		// 01/01/2000 is on a Saturday so we need to offset our totalDays
		int dayOfWeek_i32 = (totalDays + 6) % 7;
		
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

	bool BirthdayCalc::isLeapYear()
	{
		if ( ((m_year_i32 % leapYearNum == 0) &&
				(m_year_i32 % dumbLeapYearNum != 0))
			||
			(m_year_i32 % extraDumbLeapYearNum == 0) )
		{
			return true;
		}
		return false;
	}

	void BirthdayCalc::printDate()
	{
		std::cout << m_month_i32 << "/";
		std::cout << m_day_i32 << "/";
		std::cout << m_year_i32 << std::endl;
	}
}