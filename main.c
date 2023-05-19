#include "shell.h"
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */


// int main(void)
// {
// 	char *input = NULL;
// 	char *tokens[MAX_INPUT_SIZE];
// 	char *path;
// 	size_t len = 0;
// 	char *token;
// 	int i;

// 	while (1)
// 	{
// 		write(1, "cisfun$ ", 9);
// 		_getline(&input, &len, stdin);
// 		input[strcspn(input, "\n")] = 0;
		
// 		token = _strtok(input, " ");
// 		i = 0;
// 		while (token != NULL)
// 		{
// 			tokens[i] = token;
// 			i++;
// 			token = _strtok(NULL, " ");
// 		}
// 		tokens[i] = NULL;

// 		if (_strcmp(tokens[0], "env") == 0)
// 		{
// 			env_builtin();
// 			continue;
// 		}
// 		else if (_strcmp(tokens[0], "exit") == 0)
// 		{
// 			exit_builtin(tokens);
// 		}
// 		else if (_strcmp(tokens[0], "cd") == 0)
// 		{
// 			path = tokens[1];
// 			cd_builtin(path);
// 		}
// 		else
// 		{
// 			execute_command(tokens);
// 		}
// 		fflush(stdout);
// 	}
// 	free(input);
// 	return (0);
// }

char *get_current_dir() {
    char *cwd = malloc(MAX_INPUT_SIZE);
    if (cwd == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    if (getcwd(cwd, MAX_INPUT_SIZE) == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }
    return cwd;
}

int main(void) {
    char *input = NULL;
    char *tokens[MAX_INPUT_SIZE];
    char *path;
    size_t len = 0;
    char *token;
    int i;

    while (1) {
        char *cwd = get_current_dir();
        write(STDOUT_FILENO, "cisfun:", strlen("cisfun:"));
        write(STDOUT_FILENO, cwd, strlen(cwd));
        write(STDOUT_FILENO, "$ ", 2);
        free(cwd);

        ssize_t bytes_read = _getline(&input, &len, stdin);
        if (bytes_read == -1) {
            perror("getline");
			exit(EXIT_FAILURE);
            break;
        }
        if (bytes_read == 0) {
            continue;
        }

        input[strcspn(input, "\n")] = 0;

        token = strtok(input, " ");
        i = 0;
        while (token != NULL) {
            tokens[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        tokens[i] = NULL;

        if (strcmp(tokens[0], "env") == 0) {
            env_builtin();
            continue;
        }
        else if (strcmp(tokens[0], "exit") == 0) {
            exit_builtin(tokens);
        }
        else if (strcmp(tokens[0], "cd") == 0) {
            path = tokens[1];
            cd_builtin(path);
        }
        else {
            execute_command(tokens);
        }
        fflush(stdout);
    }
    free(input);
    return 0;
}
