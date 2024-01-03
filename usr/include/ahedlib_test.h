#ifndef AHEDLIB_TEST_H
#define AHEDLIB_TEST_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#define RED_TEXT    "\x1B[31m"
#define GREEN_TEXT  "\x1B[32m"
#define RESET_COLOR "\x1B[0m"

void _test_invalid_valid_dir(int argc, char **argv);
void _test_invalid_args_valid_args(int argc, char **argv);
#endif
