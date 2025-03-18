/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:12:45 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/18 02:55:56 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	get_height(t_map *map)
{
	int	i;

	i = 0;
	while (map->arr[i])
		i++;
	return (i);
}

void	get_window(t_map *map, t_list *list)
{
	map->arr = lst_to_arr(list);
	if (!map->arr)
		simple_error(list);
	map->height = get_height(map);
	map->width = ft_strlen(map->arr[0]);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->width * 100,
			map->height * 100, "so_long");
}
