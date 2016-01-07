#include "minishell.h"

void    ft_puttab(char **tab)
{
    int i;
    
    i = 0;
    while (tab[i])
    {
        ft_putendl(tab[i]);
        i++;
    }
}

void    tabdel(char ***tab)
{
    int i;
    
    i = 0;
    while ((*tab)[i])
    {
        free((*tab)[i]);
        (*tab)[i] = NULL;
        i++;
    }
    free(*tab);
    *tab = NULL;
}

int tablen(char **tab)
{
    int i;
    
    i = 0;
    while (tab[i])
        i++;
    return (i);
}

char **tab_dup(char **env)
{
    int i;
    char **dup;
    
    dup = (char **)malloc(sizeof(char *) * (tablen(env) + 1));
    i = 0;
    while (env[i])
    {
        dup[i] = ft_strdup(env[i]);
        i++;
    }
    dup[i] = NULL;
    return (dup);
}
