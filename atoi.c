#include "shell.h"


int interactive()
{
 	return (isatty(STDIN_FILENO));
}
