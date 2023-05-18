#include "shell.h"


/**
 *
 *
 *
 *
 *
 */


int main()
{
	char *line;

	while (1)
	{
		print_prompt();
		line = get_line();
		if (line == NULL)
		{
			break;
		}
		
		if (_strlen(line) == 0)
		{
			free(line);
			continue;
		}

		execute_command(line);

		free(line);
	}

	return (0);
}	
