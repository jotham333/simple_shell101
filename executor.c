#include "shell.h"



/**
 * execute_command - execute a command
 *
 * @tokens: array of tokens
 *
 * Return: void
 */


 int execute_command(char **tokens)
{
    char *path, *path_copy, *token;
    pid_t pid;
    int status;
    char bin_path[MAX_INPUT_SIZE];

    pid = fork();

    if (pid == -1)
    {
        perror("fork failed");
		exit(EXIT_FAILURE);
        return -1;
    }

    if (pid == 0)
    {
        if (tokens[0][0] == '/')
        {
            execve(tokens[0], tokens, NULL);
        }
        else
        {
            path = _getenv("PATH");
            path_copy = _strdup(path);
            token = strtok(path_copy, ":");

            while (token != NULL)
            {
                _strcpy(bin_path, token);
                _strcat(bin_path, "/");
                _strcat(bin_path, tokens[0]);
                execve(bin_path, tokens, NULL);
                token = strtok(NULL, ":");
            }
            free(path_copy);
            perror(tokens[0]);
            exit(EXIT_FAILURE);
        }
    }

    waitpid(pid, &status, 0);
	return 0;
}


/*
int execute_command(char **tokens) {
  // Execute the command
  pid_t pid = fork();

  if (pid < 0) {
    perror("Fork failed");
    return -1;
  } else if (pid == 0) {
    // Child process
    execvp(tokens[0], tokens);
    perror("Execvp failed");
    exit(EXIT_FAILURE);
  } else {
    // Parent process
    int status;
    waitpid(pid, &status, 0);

    if (WIFEXITED(status)) {
      // Command executed successfully
      return WEXITSTATUS(status);
    } else {
      // Command terminated abnormally
      return -1;
    }
  }
}*/

/**
int execute_command(char **tokens) {
  int result = 0; // Result of the last executed command
  int i = 0; // Index for iterating over tokens
  int status;

  while (tokens[i] != NULL) {
    if (strcmp(tokens[i], "&&") == 0) {
      // Execute the next command only if the previous one succeeded
      if (result == 0) {
        result = execute_subcommand(&tokens[i + 1]);
      }
      i++; // Skip the next command token
    } else if (strcmp(tokens[i], "||") == 0) {
      // Execute the next command only if the previous one failed
      if (result != 0) {
        result = execute_subcommand(&tokens[i + 1]);
      }
      i++; // Skip the next command token
    } else {
      // Execute a single command
      result = execute_subcommand(&tokens[i]);
    }

    i++;
  }

  return result;
}

*

int execute_command(char **tokens) {
  int result = 0; // Result of the last executed command
  int i = 0; // Index for iterating over tokens
  int status;

  while (tokens[i] != NULL) {
    if (strcmp(tokens[i], "&&") == 0) {
      // Execute the next command only if the previous one succeeded
      if (result == 0) {
        execute_subcommand(tokens[i + 1], 0, NULL);
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
          result = 0; // Command succeeded
        } else {
          result = 1; // Command failed
        }
      }
      i++; // Skip the next command token
    } else if (strcmp(tokens[i], "||") == 0) {
      // Execute the next command only if the previous one failed
      if (result != 0) {
        execute_subcommand(tokens[i + 1], 0, NULL);
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
          result = 0; // Command succeeded
        } else {
          result = 1; // Command failed
        }
      }
      i++; // Skip the next command token
    } else {
      // Execute a single command
      execute_subcommand(tokens[i], 0, NULL);
      wait(&status);
      if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
        result = 0; // Command succeeded
      } else {
        result = 1; // Command failed
      }
    }

    i++;
  }

  return result;
}





void execute_subcommand(char *command, int arg_count, char **args) {
  // Split the command into arguments using whitespace
  int num_arguments = 0;
  char *arguments[MAX_INPUT_SIZE + 2]; // Extra space for command and NULL terminator

  char *token = strtok(command, " ");
  while (token != NULL) {
    arguments[num_arguments++] = token;
    token = strtok(NULL, " ");

    if (num_arguments > MAX_INPUT_SIZE) {
      fprintf(stderr, "Too many arguments\n");
      return;
    }
  }

  arguments[num_arguments] = NULL;

  // Execute the sub-command
  int status;
  if (fork() == 0) {
    // Child process
    execvp(arguments[0], arguments);
    exit(EXIT_FAILURE);
  } else {
    // Parent process
    wait(&status);
  }
}*/
