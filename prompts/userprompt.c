#include "userprompt.h"
#include <stdio.h>

void print_user(char *cwd, char *name, char *host)
{
	printf("%s@%s:%s$ ", name, host, cwd);
}