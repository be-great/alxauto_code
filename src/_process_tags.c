#include "../usr/include/ahedlib.h"
/**
* process_tags - search the pattern and save it
* into temporally file "filterd_tag"
* @directory_path: the dir path
*/
void process_tags(char *directory_path)
{
	char command[256];

	snprintf(command, sizeof(command),
"cat %stags | sed -n '/^!/d; s@^.*/\\(.*\\)/\\(.*\\)$@\\1@p' | sed 's/;$//' | uniq | sed '/int main(/d' | sed '/.*:/d' | sed '/^/!s/^/^/; s/$/;/; s/\\^//g'> %sfiltered_tag ",
		directory_path, directory_path);
	system(command);

	/*remove the $ at the end of the filtered function*/
	snprintf(command, sizeof(command),
	    "sed -i 's/\\$;/;/g' %sfiltered_tag", directory_path);
	system(command);
}
