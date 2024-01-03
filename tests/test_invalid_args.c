#include "../usr/include/ahedlib_test.h"

/**
* _test_invalid_args - Test invalid args
* @argc: number of argument pass
* @argv: the argument vector
* Exit: exit -1 if failure
*/
void _test_invalid_args(int argc, char **argv)
{
	char command[256];

	snprintf(command, sizeof(command),
			"./build/alxauto -t . -H main.h");

	int result = system(command);

	if (result != 0)
	{
		printf(GREEN_TEXT "1- Test Passed: For invalid flag."
				 RESET_COLOR "\n");
	}
	else
	{
		printf(RED_TEXT "1- Test Failed:  For invalid flag."
				RESET_COLOR "\n");
	}
}
