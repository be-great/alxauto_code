#ifndef MAIN_H
#define MAIN_H

int _strlen(const char *s);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void __attribute__((constructor)) bmain();
void free_list(list_t *head);
size_t list_len(const list_t *h);
size_t print_list(const list_t *h);

#endif
