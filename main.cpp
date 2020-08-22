#include "helper.h"

int main(int argc, char* argv[])
{
	BirthdaysAreFun::BirthdayCalc birthdayCalc_c;

	BirthdaysAreFun::handleInput(argv, birthdayCalc_c);

	BirthdaysAreFun::calcDayOfWeek(birthdayCalc_c);

	BirthdaysAreFun::outputAnswer(birthdayCalc_c);

	return 0;
}