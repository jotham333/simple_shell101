#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *find_command(char *command);
char **tokenize(char *str);

int main() {
    char input[1024];
    char *path_env = getenv("PATH");
    char **tokens;
    char *path;
    pid_t pid;
    int status;

    while (1) {
        printf("cisfun$ ");
        fgets(input, sizeof(input), stdin);

        input[strlen(input) - 1] = '\0';

        tokens = tokenize(input);
        path = find_command(tokens[0]);

        if (path == NULL) {
            printf("command not found: %s\n", input);
            continue;
        }

        pid = fork();

        if (pid == -1) {
            perror("fork failed");
            return 1;
        }

        if (pid == 0) {
            execve(path, tokens, NULL);
            perror(input);
            exit(EXIT_FAILURE);
        }

        waitpid(pid, &status, 0);
    }

    return 0;
}

char *find_command(char *command) {
    char *path_env = getenv("PATH");
    char *token;
    char *path;

    while ((token = strsep(&path_env, ":")) != NULL) {
        path = malloc(strlen(token) + strlen(command) + 2);

        if (path == NULL) {
            perror("Memory allocation failed");
            return NULL;
        }

        sprintf(path, "%s/%s", token, command);

        if (access(path, F_OK) == 0) {
            return path;
        }

        free(path);
    }

    return NULL;
}

char **tokenize(char *str) {
    char **tokens = NULL;
    char *token = strtok(str, " ");
    int i = 0;

    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char *) * (i + 1));
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, " ");
    }

    tokens = realloc(tokens, sizeof(char *) * (i + 1));
    tokens[i] = NULL;

    return tokens;
}
