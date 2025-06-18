#include <stdio.h>
#include "input.h"

void getinp(char *buf)
{
        fgets(buf, sizeof(buf), stdin);
}