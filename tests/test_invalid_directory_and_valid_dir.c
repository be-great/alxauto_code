#include "../usr/include/ahedlib_test.h"

/**
* _test_invalid_valid_dir - Test valid and invalid directory
* @argc: number of argument pass
* @argv: the argument vector
* Exit: exit -1 if failure
*/
void _test_invalid_valid_dir(int argc, char **argv)
{
	char validcommand[256], invalidcommand[256];
    int resultvalid, resultinvalid;


	snprintf(validcommand, sizeof(validcommand),
			"./build/alxauto -D . -H main.h");

    snprintf(invalidcommand, sizeof(invalidcommand),
			"./build/alxauto -D sradnom -H main.h");

	resultvalid = system(validcommand);
    
	if (resultvalid == 0)
	{
		printf(GREEN_TEXT "1- Test Passed: For valid directory."
				 RESET_COLOR "\n");
	}
	else
	{
		printf(RED_TEXT "1- Test Failed:  For valid directory."
				RESET_COLOR "\n");
	}
    resultinvalid = system(invalidcommand);

    if (resultinvalid != 0)
	{
		printf(GREEN_TEXT "1- Test Passed: For invalid directory."
				 RESET_COLOR "\n");
	}
	else
	{
		printf(RED_TEXT "1- Test Failed:  For invalid directory."
				RESET_COLOR "\n");
	}
}
