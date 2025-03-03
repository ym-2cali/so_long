#include "../../inc/so_long.h"

int	check_form(t_list *map)
{
	int		len;
	t_node	*tmp;

	len = ft_strlen(map->head->content);
	tmp = map->head->next;
	while(tmp)
	{
		if (len != ft_strlen(tmp->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int count_elements(t_list *map, char c)
{
	t_node	*tmp;
	int		i;
	int		count;

	count = 0;
	tmp = map->head;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (tmp->content[i] == c)	
				count++;
			i++;
		}
		tmp = tmp->next;
	}
	return (count);
}

int	validate_elements(t_list *list)
{
	if (count_elements(list, 'E') != 1
		|| count_elements(list, 'P') != 1
		|| count_elements(list, 'C') < 1)
		return (0);
	return (1);
}