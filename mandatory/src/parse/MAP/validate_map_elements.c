/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:22:54 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/18 02:52:42 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

int	ft_berlin(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	check_form(t_list *map)
{
	int		len;
	t_node	*tmp;

	len = ft_berlin(map->head->content);
	tmp = map->head->next;
	while (tmp)
	{
		if (len != ft_berlin(tmp->content))
			return (0);
		else if ((tmp->content[ft_berlin(tmp->content)] == '\n')
			&& tmp->next == NULL)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	count_elements(t_list *map, char c)
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

int	validate_size(t_list *list)
{
	int	width;
	int	height;

	width = (ft_strlen(list->head->content) - 1) * 100;
	height = (list->size - 1) * 100;
	if (width > 2560 || height > 1440)
		return (0);
	return (1);
}
