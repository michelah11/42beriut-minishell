#include "../includes/minishell.h"

void    echo(char *line, int n)
{
    int i;

    i = 0;
    if (!line)
        return ;
    printf("%s", line);
    if (n)
        printf("%%");
    printf("\n");
}