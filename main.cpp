#include "helper.h"

int main(int argc, char* argv[])
{
	BirthdayCalc birthdayCalc_c;

	handleInput(argv, birthdayCalc_c);

	birthdayCalc_c.printDate();
}