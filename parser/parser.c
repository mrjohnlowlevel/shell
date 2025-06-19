#include "parser.h"
#include <string.h>
#include <stdlib.h>

char **to_tokens(char *buf)
{
        char *delim = " ";
        char *token = strtok(buf, delim);
        int i = 0;

        char **tokens = malloc(32 * sizeof(char*));  // Allow up to 32 tokens


        if (!tokens)
                return NULL;

        while (token != NULL && i < 32) {
                tokens[i++] = token;
                token = strtok(NULL, delim);
        }

        tokens[i] = NULL;

        return tokens;
}

void free_tokens(char **tokens)
{
        if (!tokens)
                return;
        free(tokens);
}
