#include "../includes/minishell.h"


int ft_envplen(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
        i++;
    return (i);
}

void    ft_print_envp(char  **envp)
{
    int i;

    i = 0;
    while(envp[i])
    {
        printf("%s\n", envp[i++]);
    }
}

char    *ft_findmax(char **envp)
{
    int i;
    char    *max;

    i = 0;
    max = envp[0];
    while (envp[i])
    {
        if (ft_strcmp(envp[i], max) > 0)
            max = envp[i];
        i++;
    }
    return (max);
}

int ft_export_list(char **envp, char **new_envp)
{
    int i;
    char    *prev;
    char    *min;
    int j;

    prev = NULL;
    i = 0;
    while (envp[i])
    {
        j = 0;
        min = ft_findmax(envp);
        while (envp[j])
        {
            if ((ft_strcmp(envp[j], min) < 0 && !prev) || (ft_strcmp(envp[j], min) < 0 && ft_strcmp(envp[j], prev) > 0))
                 min = envp[j];
            j++;
        }
            prev = min;
            new_envp[i] = ft_strdup(min);
        i++;
    }
    new_envp[i - 1] = NULL; 
    return (0);
}

int ft_is_valid(char *cmd)
{
    int i;

    i = 1;
    if (!ft_isalpha(cmd[0]) && cmd[0] != '_')
        return (0);
    while (cmd[i] && cmd[i] != '=')
    {
        if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
            return (0);
        i++;
    }
    return (1);
}

int ft_env_exist(char *cmd)
{
    size_t i;
    int j;

    i = 0;
    j = 0;
    while (cmd[i] && cmd[i] != '=')
        i++;
    if (i == ft_strlen(cmd))
        return (0);
    while (data.env[j])
    {
        if (!ft_strnstr(cmd, data.env[j], i))
            return (1);
        j++;
    }
    return (0);
}

int ft_change_env(char *cmd)
{

}

int ft_export(char **cmd, char **envp)
{
    int i;

    i = 1;
    if (!cmd[i])
        ft_print_envp(envp);
    else
    {
        while (cmd[i])
        {
            if (ft_is_valid(cmd[i]))
            {
                if (ft_env_exist(cmd[i]))
                {
                    ft_change_env(cmd[i]);
                }
                else
                {
                    ft_add_env(cmd[i]);
                }
            }
            i++;
        }
    }
    return (0);
}