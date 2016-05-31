#include <rtv1.h>

void	modif_all_lights(t_tool *k, double value)
{
	t_light *ptr;

	ptr = k->rt->l_lights;
	if (k->rt->l_lights == NULL)
		return;
	while (ptr != NULL)
	{
		ptr->lumdiff += value;
		ptr = ptr->next;
	}
}

void	modif_lumamb(t_tool *k, double value)
{
	k->rt->lumamb += value;
}