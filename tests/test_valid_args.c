#include "../usr/include/ahedlib_test.h"

/**
* _test_valid_args - Test invalid args
* @argc: number of argument pass
* @argv: the argument vector
* Exit: exit -1 if failure
*/
void _test_valid_args(int argc, char **argv)
{
	char command[256];

	snprintf(command, sizeof(command),
			"./build/alxauto  -D . -H main.h");

	int result = system(command);

	if (result == 0)
	{
		printf(GREEN_TEXT "2- Test Passed: For valid flag."
				 RESET_COLOR "\n");
	}
	else
	{
		printf(RED_TEXT "2- Test Failed: For valid flag"
				RESET_COLOR "\n");
		exit(-1);
	}
}
