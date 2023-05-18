#include "shell.h"



/**
 *
 *
 *
 *
 *
 *
 */

char **tokenize(char *str)
{
        char **tokens = NULL;
        char *token = strtok(str, " ");
        int i = 0;

        while (token != NULL)
        {
                tokens = realloc(tokens, sizeof(char *) * (i + 1));
                tokens[i] = strdup(token);
                i++;
                token = strtok(NULL, " ");
        }

        tokens = realloc(tokens, sizeof(char *) * (i + 1));
        tokens[i] = NULL;

        return tokens;
}
