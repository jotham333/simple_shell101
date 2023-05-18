#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

extern char **environ;

#define MAX_LENGTH 1024

/* 1-helper_functions */
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dest, const char *src);
int _strlen(char *str);
char *_strcat(char *dest, const char *src);
void *_memmove(void *dest, const void *src, size_t n);


/* putchar.c */
char _putchar(char c);
int interactive();

/* shell.c */
void execute_command(char *command);
char *get_line();
void print_prompt();

/* 2-helper_functions */
char *_strchr(char *str, int c);


/* tokenizer */
char **tokenize(char *str);



/* getenv */
char *_getenv(char *name);
char *find_command(char *command);



#endif /*SHELL_H */
