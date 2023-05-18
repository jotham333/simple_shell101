#include "shell.h"



/**
 * _putchar - print a character tio the console
 *
 * @c: the character to be printed
 *
 * Return: the printed chracter
 */

char _putchar(char c)
{
	return (write(1, &c, 1));
}



/**
 * interctive - to check if the shell is intreactive
 *
 * Return: 1 if shell is interactive and 0 otherwise
 */

int interactive()
{
	return (STDIN_FILENO);
}





























