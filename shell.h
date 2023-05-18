#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>

extern char **environ;

#define MAX_INPUT_SIZE 1024

/* builtin.c */
void env_builtin();
void exit_builtin(char **tokens);

/* executor.c */
void execute_command(char **tokens);



/* tokenize.c */
char **tokenize(char *str);

/*environ.c */
char *_getenv(char *name);


/* string1.c */
size_t _strlen(char *str);
int _strcmp(const char *str1, const char *str2);
int _strncmp(char *str1, char *str2, size_t n);



#endif
