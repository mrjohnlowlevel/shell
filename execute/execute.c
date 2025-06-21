#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void exec_args(char **tokens, const int size)
{
        const pid_t pid = fork();

        if (pid == 0) {
                execvp(tokens[0], tokens);
                perror("executing file error");
                exit(1);
        }
        else if (pid > 0) {
                waitpid(pid, NULL, 0);
        }
        else {
                perror("fork failed");
                exit(1);
        }
}
