#include "../usr/include/ahedlib.h"

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
	fprintf(output_file, "#ifndef HEADER_H\n");
	fprintf(output_file, "#define HEADER_H\n\n");

	while (fgets(line, sizeof(line), input_file))
	{
		/* Write the function prototype to the output file*/
		fprintf(output_file, "%s", line);
	}
	fprintf(output_file, "\n#endif /* AUTO_HEADER */\n");

}
