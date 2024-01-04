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
"cat %stags | sed -n 's/^.*\\/\\(.*\\)/\\1/p' | sed 's/\\(.*\\)\\$.*/\\1/' | sed 's/;$//' | uniq | sed '/int main(/d' | sed '/.*:/d' | sed 's/$/;/g' > %sfiltered_tag",
directory_path, directory_path);
}