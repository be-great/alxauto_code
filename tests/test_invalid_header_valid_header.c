#include "../usr/include/ahedlib_test.h"
/**
 * _test_invalid-valid_header - Test invalid and valid header
 * @argc: number of arguments passed
 * @argv: argument vector
 * Exit: -1 upon failure
*/

void _test_invalid_valid_header(int argc, char **argv)
{
    char validcommand[256], invalidcommand[256];
    int resultvalid, resultinvalid;

    snprintf(validcommand, sizeof(validcommand),
			"./build/alxauto -D . -H main.h");

    snprintf(invalidcommand, sizeof(invalidcommand),
			"./build/alxauto -D . -r main.h");

    resultvalid = system(validcommand);
    if (resultvalid == 0)
    {
        printf(GREEN_TEXT "1- Test Passed: For valid header."
				 RESET_COLOR "\n");
    }
    else
    {
        printf(RED_TEXT "1- Test Failed:  For valid header."
				RESET_COLOR "\n");
    }

    resultinvalid = system(invalidcommand);

    if (resultinvalid != 0)
	{
		printf(GREEN_TEXT "1- Test Passed: For invalid header."
				 RESET_COLOR "\n");
	}
	else
	{
		printf(RED_TEXT "1- Test Failed:  For invalid header."
				RESET_COLOR "\n");
	}
}
