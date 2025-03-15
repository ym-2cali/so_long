/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:09:53 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/15 21:04:38 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	get_img(t_map *map)
{
	int	w;
	int	h;

	map->exit_img = mlx_xpm_file_to_image(map->mlx, "exit.xpm", &w, &h);
	map->floor_img = mlx_xpm_file_to_image(map->mlx, "floor.xpm", &w, &h);
	map->wall_img = mlx_xpm_file_to_image(map->mlx, "wall.xpm", &w, &h);
	map->player_img = mlx_xpm_file_to_image(map->mlx, "player.xpm", &w, &h);
	map->col_img= mlx_xpm_file_to_image(map->mlx, "coin.xpm", &w, &h);
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
		{
			if (map->arr[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->wall_img, j * 100, i * 100);
			else if (map->arr[i][j] == '0')
				mlx_put_image_to_window(map->mlx, map->win, map->floor_img, j * 100, i * 100);
			else if (map->arr[i][j] == 'P')
			{
				map->player_pos.x = j;	
				map->player_pos.y = i;
				mlx_put_image_to_window(map->mlx, map->win, map->player_img, j * 100, i * 100);
			}
			else if (map->arr[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->exit_img, j * 100 , i * 100);
			else if (map->arr[i][j] == 'C')
			{
				map->col++;
				mlx_put_image_to_window(map->mlx, map->win, map->col_img, j * 100 , i * 100);
			}
		}
	}
}

int	h_events(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
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
