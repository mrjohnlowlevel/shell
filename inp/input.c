#include <stdio.h>
#include "input.h"

void getinp(char *buf, size_t size)
{
        fgets(buf, size, stdin);
}