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
#include <ctype.h>
#include <stdbool.h>

extern char **environ;

#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 1024


/* builtin.c */
void env_builtin();
void exit_builtin(char **tokens);
int cd_builtin(char *path);
char *get_current_dir();

/* executor.c */
int execute_command(char **tokens);
void execute_commands(char *commands);
void execute_subcommand(char *command, int arg_count, char **args);

/* tokenize.c */
char **tokenize(char *str);
char *_strtok(char *str, char *delim);



/*environ.c */
char *_getenv(char *name);
ssize_t _getline(char **lineptr, size_t *line_size, FILE *stream);
int _unsetenv(char *name);
int _setenv(const char *name, const char *value, int overwrite);


/* string1.c */
size_t _strlen(char *str);
int _strcmp(const char *str1, const char *str2);
int _strncmp(char *str1, char *str2, size_t n);
size_t _strcspn(const char *str, const char *charset);


/* string2.c */
char *_strcpy(char *destination, char *srcource);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strchr(char *str, char character);
int _isspace(int c);

/*alias.c*/
void alias_builtin(char **tokens);
void unset_alias(char *name);
void unalias_builtin(char **tokens);

/* atoi */
bool interactive();

/* memory */
void *_realloc(void *ptr, size_t new_size);
void *_memcpy(void *dest, const void *src, size_t num_bytes);
#endif
