#include <unistd.h>
#include "getuser.h"
#include <pwd.h>

char *get_name(void)
{
        struct passwd *buf = getpwuid(getuid());
        
        if (buf == NULL) {
                return NULL;
        }
        else {
                return buf->pw_name;
        }
        
}

char *get_cwd(char *cwd, size_t size)
{
        char *buf = getcwd(cwd, size);
        
        if (buf != NULL) {
                return buf;
        }
        else {
                return NULL;
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