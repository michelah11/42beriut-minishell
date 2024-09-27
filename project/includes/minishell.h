#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include "../libft/libft.h"
# include "tokens.h"

typedef struct s_minishell
{
    char **env;
    char **export_env;
    char **user_env;
    t_parser *parser;
} t_minishell;

int pwd(void);
void    echo(char *line, int n);
int cd(char *path);
int ft_export(char **cmd, char **envp);
int ft_envplen(char **envp);
int ft_export_list(char **envp, char **new_envp);
void    ft_print_envp(char  **envp);

extern t_minishell data;

#endif