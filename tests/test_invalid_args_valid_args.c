#include "../usr/include/ahedlib_test.h"

/**
* _test_invalid_args_valid_args - Test invalid and valid args
* @argc: number of argument pass
* @argv: the argument vector
* Exit: exit -1 if failure
*/
void _test_invalid_args_valid_args(int argc, char **argv)
{
	char validcommand[256], invalidcommand[256];
	int resultvalid, resultinvalid;


	snprintf(invalidcommand, sizeof(invalidcommand),
			"./build/alxauto -t . -H main.h");
	snprintf(validcommand, sizeof(validcommand),
			"./build/alxauto -D . -H main.h");

	resultinvalid = system(invalidcommand);

	if (resultinvalid != 0)
	{
		printf(GREEN_TEXT "1- Test Passed: For invalid flag."
				 RESET_COLOR "\n");
	}
	else
	{
		printf(RED_TEXT "1- Test Failed:  For invalid flag."
				RESET_COLOR "\n");
	}
	resultvalid = system(validcommand);
	if (resultvalid == 0)
	{
		printf(GREEN_TEXT "2- Test Passed: For valid flag."
				 RESET_COLOR "\n");
	}
	else
	{
		printf(RED_TEXT "2- Test Failed: For valid flag"
				RESET_COLOR "\n");
	}

}
