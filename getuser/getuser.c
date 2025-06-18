#include <unistd.h>
#include "getuser.h"
#include <pwd.h>

char *get_name(void)
{
        char *user = getpwuid(getuid())->pw_name;
        if (user != NULL) {
                return user;
        }
        else {
                return "Unknown";
        }
}

char *get_cwd(char *cwd, size_t size)
{
        char *buf = getcwd(cwd, size);
        
        if (buf != NULL) {
                return buf;
        }
        else {
                return "NULL";
        }
}

char *get_host(char *host, size_t size)
{
        if (gethostname(host, size) < 0) {
                return NULL;
        }
        else {
                return host;
        }
}