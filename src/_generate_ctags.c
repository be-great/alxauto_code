#include "../usr/include/ahedlib.h"
/**
* generate_ctags - generate the tags of the c files
* @directory_path: the dir path
*/
void generate_ctags(char *directory_path)
{
	char command[256];
	char new_dir[208];

	strcpy(new_dir, directory_path);
	strcat(new_dir, "tags");

	snprintf(command, sizeof(command),
				"ctags -R --c-kinds=+p --fields=+S --extra=+q -o %s", new_dir);
	/*execute the command*/
	system(command);

}