#include "shell.h"

int main (void)
{
    if (_isatty(stdin))
    {
        _isactive();
    }
    else
    {
        _isnactive();
    }
    return (0)
}