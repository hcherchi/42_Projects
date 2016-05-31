#include <rtv1.h>

void	clean_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		if (tab)
		{
			free(tab);
			tab = NULL;
		}
	}
}
