#include "../includes/minishell.h"

t_minishell data;

int ft_init_envp(char **envp)
{
    char    **new_envp;

    data.env = envp;
    new_envp = (char **)malloc(sizeof(char *) * ft_envplen(envp));
    ft_export_list(envp, new_envp);
    data.export_env = new_envp;
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    char    *line;
    char    **cmd;

    ft_init_envp(envp);
    (argc = 0, argv =NULL);
    while (1) {
        line = readline("minishell>");
        if (line == NULL)
            return (0);
        add_history(line);
        cmd = ft_split(line, ' ');
        if (ft_strnstr("echo", cmd[0], 4))
            echo (cmd[1] , 1);
         if (ft_strnstr("pwd", cmd[0], 3))
            pwd();
        if (ft_strnstr("cd", cmd[0], 2))
            cd(cmd[1]);
        
        if (ft_strnstr(cmd[0], "export", 6)) 
            ft_export(cmd, data.export_env);
    }
    
    return (0);
}