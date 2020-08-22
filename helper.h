#include <iostream>
#include <sstream>
#include <string>

namespace BirthdaysAreFun
{
	namespace DaysPerMonth
	{
		const int JANUARY = 31;
		const int FEBRUARY = 59;
		const int MARCH = 90;
		const int APRIL = 120;
		const int MAY = 151;
		const int JUNE = 181;
		const int JULY = 212;
		const int AUGUST = 243;
		const int SEPTEMBER = 273;
		const int OCTOBER = 304;
		const int NOVEMBER = 334;
	}

	const int leapYearNum = 4;
	const int dumbLeapYearNum = 100;
	const int extraDumbLeapYearNum = 400;

	class BirthdayCalc
	{
	public:
		BirthdayCalc();

		int getMonth();
		int getDay();
		int getYear();
		std::string getDayOfWeek();

		void setMonth(int num);
		void setDay(int num);
		void setYear(int num);
		void setDayOfWeek(std::string str);

		bool isLeapYear();

		void printDate();

	private:
		int m_month_i32;
		int m_day_i32;
		int m_year_i32;
		std::string m_dayOfWeek_str;
	};

	void handleInput(char* argv[], BirthdayCalc& birthdayCalc_c);

	void calcDayOfWeek(BirthdayCalc& birthdayCalc_c);

	int calcDaysUpToYear(BirthdayCalc& birthdayCalc_c);

	int calcDaysUpToMonth(BirthdayCalc& birthdayCalc_c);

	void finalDayOfTheWeek(BirthdayCalc& birthdayCalc_c, int totalDays);

	void outputAnswer(BirthdayCalc& birthdayCalc_c);
}