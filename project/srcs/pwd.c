#include "../includes/minishell.h"

int pwd(void)
{
    char    *buf;

    buf = NULL;
    buf = getcwd(buf, 1024);
    if (buf)
    {
        printf("%s\n", buf);
        return (0);
    }
    return (errno);
}