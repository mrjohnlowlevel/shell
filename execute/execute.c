#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void exec_args(char **tokens, const int size)
{
        int pipefd[2];
        pipe(pipefd);

        if (pipe(pipefd) == -1) {
                perror("pipe");
                exit(EXIT_FAILURE);
        }

        for (int i = 0; i < size; i++) {
                if (strcmp(tokens[i], "|") == 0) {
                        pid_t cpid2 = fork();
                        pid_t cpid1 = fork();

                        if (cpid1 == 0) {
                                dup2(pipefd[1], STDOUT_FILENO);
                                close(pipefd[0]);
                                close(pipefd[1]);

                                execvp(tokens[0], tokens);
                                perror("execvp");
                                exit(EXIT_FAILURE);
                        }

                        if (cpid2 == 0) {
                                dup2(pipefd[0], STDIN_FILENO);
                                close(pipefd[0]);
                                close(pipefd[1]);

                                execvp(tokens[0], tokens);
                                perror("execvp");
                                exit(EXIT_FAILURE);
                        }
                }
        }

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
