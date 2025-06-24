#ifndef PARSER_H
#define PARSER_H

char **to_tokens(char *buf, char *delim);
void free_tokens(char **tokens);

#endif
