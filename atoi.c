#include "shell.h"



/**
 * interactive - checks if shell is interactive
 *
 * Return: true if shell is interactive and false otherwise
 */

bool interactive(void)
{
	return (isatty(STDIN_FILENO));
}




/**
 * _atoi - extract integer from string
 * @str: the string argument
 *
 * Return: type integer
 */

int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;
	int digit;

	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
			{
				break;
			}

			i++;
			continue;
		}

		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			result = result * 10 + digit;
		}
		else if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
			break;

		i++;
	}

	return (sign * result);

}
