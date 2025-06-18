#include <stdio.h>
#include <unistd.h>
#include "getuser.h"
#include "userprompt.h"

int main()
{
	if (isatty(STDIN_FILENO)) {
		char *name = get_name();
		char host[1024];
		int hst = get_host(host, sizeof(host));
		char *cwd = get_cwd(cwd, sizeof(cwd));
		print_user(cwd, name, hst);
	}
	else {
	}
}