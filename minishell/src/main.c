#include "minishell.h"

int main(int ac, char **av, char **env)
{
    char **myenv;
    
    if (ac == 1)
    {
        if (*env == NULL)
        {
            ft_putendl("Environnement destroyed");
            return (0);
        }
        myenv = tab_dup(env);
        lvlup(&myenv);
        set_commands(&myenv, av);
    }
    else
        ft_putendl("Error");
	return (0);
}
