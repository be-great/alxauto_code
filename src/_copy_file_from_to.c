#include "../usr/include/ahedlib.h"
/**
 * header_name_extract - extract the header name
 * @path: the string that have the header name
 * Return: the extracting name
 */
char *header_name_extract(char *path)
{
    /* Find the last occurrence of '/' */
    char *lastSlash;
    char *mainWithoutExtension;
	/*find the pos of last '/'*/
	lastSlash = strrchr(path, '/');
    
    if (lastSlash != NULL) {
        /* Extract the substring after the last '/' */
        path = lastSlash + 1;
		/*convert the string to upper case*/
		for (int i = 0; path[i] != '\0'; i++)
		{
                path[i] = toupper(path[i]);
        }
        
    } else {
		for (int i = 0; path[i] != '\0'; i++)
		{
                path[i] = toupper(path[i]);
        }
        /* If no '/' found, the whole string is considered as the main part */
    }
	int str_len = strlen(path);
	/* Extract the substring before the last '.' */
	mainWithoutExtension = (char *)malloc(str_len - 1);
	if (mainWithoutExtension == NULL)
	{
		return (NULL);
	}

	strncpy(mainWithoutExtension, path, str_len - 2);
	mainWithoutExtension[str_len - 1] = '\0';

	return (mainWithoutExtension);

}

/**
*  copy_file_from_to - copy neccessory header guard and the prototype function
* @header_arg: The header name
*/
void copy_file_from_to(char *header_arg)
{
	char line[512];
	FILE *output_file, *input_file;

	output_file = fopen(header_arg, "w");
	if (output_file == NULL)
	{
		fprintf(stderr, "Error opening The header file\n");
		exit(-1);
	}
	input_file = fopen("filtered_tag", "r");
	if (input_file == NULL)
	{
		fprintf(stderr, "Error opening The header file\n");
		exit(-1);
	}
	/*split the header argument with directory separator to get header name*/
	
	fprintf(output_file, "#ifndef %s_H\n", header_name_extract(header_arg));
	fprintf(output_file, "#define %s_H\n\n", header_name_extract(header_arg));

	while (fgets(line, sizeof(line), input_file))
	{
		/* Write the function prototype to the output file*/
		fprintf(output_file, "%s", line);
	}
	fprintf(output_file, "\n#endif\n");

}
