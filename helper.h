#include <iostream>
#include <sstream>
#include <string>

namespace BirthdaysAreFun
{
	const int startingVal = 6;
	const int daysPerYear = 365;
	const int leapYearNum = 4;
	const int dumbLeapYearNum = 100;
	const int daysPerWeek = 7;

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

		void printDate();

	private:
		int m_month_i32;
		int m_day_i32;
		int m_year_i32;
		std::string m_dayOfWeek_str;
	};

	enum class DaysPerMonth;

	void handleInput(char* argv[], BirthdayCalc& birthdayCalc_c);

	void calcDayOfWeek(BirthdayCalc& birthdayCalc_c);

	int calcDaysUpToYear(BirthdayCalc& birthdayCalc_c);

	int calcDaysUpToMonth(BirthdayCalc& birthdayCalc_c);

	void finalDayOfTheWeek(BirthdayCalc& birthdayCalc_c, int totalDays);

	void outputAnswer(BirthdayCalc& birthdayCalc_c);
}