#include <stdio.h>
#include <unistd.h>
#include "getuser.h"
#include "userprompt.h"
#include "input.h"
#include "parser.h"
#include "execute.h"

int main()
{
	if (isatty(STDIN_FILENO)) {
		int i = 0;
		/*Debugging counter*/
		while (i < 2)
		{
			char *name = get_name();

			char host[1024], cwd[1024];
			get_host(host, sizeof(host));
			get_cwd(cwd, sizeof(cwd));

			print_user(cwd, name, host);

			char inputbuf[1024];			// allocate dynamically later
			size_t inpbufsize = sizeof(inputbuf);
			getinp(inputbuf, inpbufsize);

			char **args = to_tokens(inputbuf, " ");
			exec_args(args, inpbufsize);
			i++;
			free_tokens(args);
		}
	}
	else {
	}
}
