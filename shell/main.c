#include <stdio.h>
#include <unistd.h>
#include "getuser.h"
#include "userprompt.h"

int main()
{
	if (isatty(STDIN_FILENO)) {
		char *name = get_name();

		char host[1024], cwd[1024];
		get_host(host, sizeof(host));
		get_cwd(cwd, sizeof(cwd));

		print_user(cwd, name, host);
	}
	else {
	}
}