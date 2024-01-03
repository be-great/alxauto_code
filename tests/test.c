#include "../usr/include/ahedlib_test.h"

/**
* main - Entry point of the test cases
* @argc: number of argument pass
* @argv: the argument vector
* Return: 0 (Success) , -1 (Failure)
*/
int main(int argc, char **argv)
{

	_test_invalid_args(argc, argv);
	_test_valid_args(argc, argv);
	_test_invalid_valid_dir(argc, argv);


	return (0);
}
