/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:09:53 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 11:12:45 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	close_window(t_map *map)
{
	destroy_image(map);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	ft_freearr(map->arr);
	exit(0);
}

void	put_img(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->win,
		map->floor_img, j * 100, i * 100);
	if (map->arr[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win,
			map->wall_img, j * 100, i * 100);
	else if (map->arr[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win,
			map->floor_img, j * 100, i * 100);
	else if (map->arr[i][j] == 'P')
	{
		map->player_pos.x = j;
		map->player_pos.y = i;
		mlx_put_image_to_window(map->mlx, map->win,
			map->player_img, j * 100, i * 100);
	}
	else if (map->arr[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win,
			map->exit_img, j * 100, i * 100);
	else if (map->arr[i][j] == 'C')
	{
		map->col++;
		mlx_put_image_to_window(map->mlx, map->win,
			map->col_img, j * 100, i * 100);
	}
}

void	draw_img(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->arr[++i])
	{
		j = -1;
		while (map->arr[i][++j])
			put_img(map, i, j);
	}
}

int	h_events(int keycode, t_map *map)
{
	if (keycode == 53)
		close_window(map);
	else if (keycode == 13)
		move_up(map);
	else if (keycode == 0)
		move_left(map);
	else if (keycode == 1)
		move_down(map);
	else if (keycode == 2)
		move_right(map);
	return (0);
}
