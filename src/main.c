#include "../usr/include/ahedlib.h"
#include <dirent.h>

/**
* checkendofdirname - check if string end with "/"
* if not add it
* @dir_arg: the directory to check
*/
void checkendofdirname(char *dir_arg)
{
	size_t length = strlen(dir_arg);

	/* Check if the string is not empty and doesn't end with '/'*/
	if (length > 0 && dir_arg[length - 1] != '/')
	{
		/* Append '/' to the end of the string*/
		strcat(dir_arg, "/");
	}
}
/**
* extensioncheck - check if the string end with the ".h"
* @str: the string
* Return: 1 if ture , else return 0
*/
int extensioncheck(char *str)
{
	size_t str_len = strlen(str);
	size_t suffix_len = strlen(".h");
	const char *end_of_str;

	if (str_len < suffix_len)
	{
		return (0);
	}

	end_of_str = str + (str_len - suffix_len);
	return (strcmp(end_of_str, ".h") == 0);
}
/**
* main - Entry point of the program
* @argc: number of argument pass
* @argv: the argument vector
* Return: 0 (Success) , -1 (Failure)
*/
int main(int argc, char **argv)
{
	DIR *dir;
	char *dir_arg = argv[2], *header_arg = argv[4];

	if (argc != 5 || strcmp(argv[1], "-D") != 0
			|| strcmp(argv[3], "-H") != 0)
		{
			fprintf(stderr,
				"Usage: %s -D <directory_path> -H <header_file_path>\n", argv[0]);
			exit(-1);
		}
	/* check existing of directory*/
	dir = opendir(dir_arg);
	if (dir == NULL)
	{
		fprintf(stderr, "Not a Vaild Directory\n");
		exit(-1);
	}
	checkendofdirname(dir_arg);
	/*right extension of header*/
	/*check extension*/
	if (!extensioncheck(header_arg))
	{
		fprintf(stderr, "Not a Vaild Header Extension\n");
		exit(-1);
	}
	/*Generate the tag and save the searched*/
	/*prototype function found into a temp file*/
	generate_ctags(dir_arg);
	process_tags(dir_arg);
	// /* open the header file and add the neccessory "header gurads" and contiant*/
	// copy_file_from_to(header_arg);
	// /*remove unwanted files tags*/
	// remove("tags");
	// remove("filtered_tag");
	return (0);
}
