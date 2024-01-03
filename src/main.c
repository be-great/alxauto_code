#include "../usr/include/ahedlib.h"
#include <dirent.h>
/**
* main - Entry point of the program
* @argc: number of argument pass
* @argv: the argument vector
* Return: 0 (Success) , -1 (Failure)
*/
int main(int argc, char **argv)
{

	DIR *dir;

	if (argc != 5 || strcmp(argv[1], "-D") != 0
			|| strcmp(argv[3], "-H") != 0)
		{
			fprintf(stderr,
				"Usage: %s -D <directory_path> -H <header_file_path>\n", argv[0]);
			exit(-1);
		}
	/* check existing of directory*/
	dir = opendir(argv[2]);
	if (dir == NULL)
	{
		perror("Not a vaild directory");
		exit(-1);
	}
	/*right extension of header*/

	return (0);
}
