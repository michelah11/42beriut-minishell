#include "../includes/minishell.h"

int cd(char *path)
{
    int i;
    char    *buf;

    i = 0;
    buf = NULL;
    if (!path)
        return (errno);
   
    if (path[0] == '~' || !path)
    {
        path = ft_strjoin("/", ft_strdup(getenv("HOME")));     
    }
    if(!chdir(path))
        return(errno);
    return (0);
}