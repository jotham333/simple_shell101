#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ALIASES 100

struct Alias
{
    char *name;
    char *command;
};

struct Alias aliases[MAX_ALIASES];
int num_aliases = 0;

void alias_builtin(char **tokens)
{
    if (tokens[1] == NULL)
    {
        /* Display all aliases */
        for (int i = 0; i < num_aliases; i++)
        {
            char *alias_str = "alias ";
            write(STDOUT_FILENO, alias_str, strlen(alias_str));
            write(STDOUT_FILENO, aliases[i].name, strlen(aliases[i].name));
            char *equal_str = "='";
            write(STDOUT_FILENO, equal_str, strlen(equal_str));
            write(STDOUT_FILENO, aliases[i].command, strlen(aliases[i].command));
            char *quote_str = "'\n";
            write(STDOUT_FILENO, quote_str, strlen(quote_str));
        }
    }
    else if (tokens[2] == NULL)
    {
        /* Display the specified alias */
        for (int i = 0; i < num_aliases; i++)
        {
            if (strcmp(tokens[1], aliases[i].name) == 0)
            {
                char *alias_str = "alias ";
                write(STDOUT_FILENO, alias_str, strlen(alias_str));
                write(STDOUT_FILENO, aliases[i].name, strlen(aliases[i].name));
                char *equal_str = "='";
                write(STDOUT_FILENO, equal_str, strlen(equal_str));
                write(STDOUT_FILENO, aliases[i].command, strlen(aliases[i].command));
                char *quote_str = "'\n";
                write(STDOUT_FILENO, quote_str, strlen(quote_str));
                return;
            }
        }
        char *error_str = "alias: ";
        write(STDERR_FILENO, error_str, strlen(error_str));
        write(STDERR_FILENO, tokens[1], strlen(tokens[1]));
        char *not_found_str = ": not found\n";
        write(STDERR_FILENO, not_found_str, strlen(not_found_str));
    }
    else if (num_aliases == MAX_ALIASES)
    {
        char *error_str = "alias: too many aliases\n";
        write(STDERR_FILENO, error_str, strlen(error_str));
    }
    else
    {
        /* Add or update the specified alias */
        char *name = tokens[1];
        char *command = tokens[2];

        /* Check if the alias already exists */
        for (int i = 0; i < num_aliases; i++)
        {
            if (strcmp(name, aliases[i].name) == 0)
            {
                /* Update the existing alias */
                free(aliases[i].command);
               aliases[i].command = strdup(command);
                return;
            }
        }

        /* Add a new alias */
        aliases[num_aliases].name = strdup(name);
        aliases[num_aliases].command = strdup(command);
        num_aliases++;
    }
}

void unset_alias(char *name)
{
    for (int i = 0; i < num_aliases; i++)
    {
        if (strcmp(name, aliases[i].name) == 0)
        {
            free(aliases[i].name);
            free(aliases[i].command);
            num_aliases--;
            for (; i < num_aliases; i++)
            {
                aliases[i] = aliases[i + 1];
            }
            return;
        }
    }
    
    const char* error_message = "unset: not an alias\n";
    write(STDERR_FILENO, error_message, strlen(error_message));
}

void unalias_builtin(char **tokens)
{
    if (tokens[1] == NULL)
    {
        const char* error_message = "unalias: too few arguments\n";
        write(STDERR_FILENO, error_message, strlen(error_message));
    }
    else
    {
        for (int i = 1; tokens[i]; i++)
        {
            unset_alias(tokens[i]);
        }
    }
}
