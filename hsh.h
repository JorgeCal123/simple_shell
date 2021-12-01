#ifndef HSH_H
#define HSH_H
/*LIBRARIES*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/*structure main.c*/
typedef struct args_s
{
    char* arg;
    struct args_s *next;
} args_t;

/*list.c*/
size_t size_list(const args_t *h);
size_t print_list(const args_t *h);
args_t *add_node(args_t **head, char* arg);

/*main.c*/
char **linkedList_to_doublePointer(args_t **head);

#endif
