/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:09:53 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/19 03:00:16 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	close_window(t_map *map)
{
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	ft_freearr(map->arr);
	exit(0);
}

void	get_img(t_map *map)
{
	int	w;
	int	h;

	map->exit_img = mlx_xpm_file_to_image(map->mlx,
			"/mnt/homes/yael-maa/so_long/img_xpm/exit.xpm", &w, &h);
	invalid_img_file(map, map->exit_img, "Invalid exit_img file or content\n");
	map->floor_img = mlx_xpm_file_to_image(map->mlx,
			"/mnt/homes/yael-maa/so_long/img_xpm/floor.xpm", &w, &h);
	invalid_img_file(map, map->floor_img,
		"Invalid floor_img file or content\n");
	map->wall_img = mlx_xpm_file_to_image(map->mlx,
			"/mnt/homes/yael-maa/so_long/img_xpm/wall.xpm", &w, &h);
	invalid_img_file(map, map->wall_img, "Invalid wall_img file or content\n");
	map->player_img = mlx_xpm_file_to_image(map->mlx,
			"/mnt/homes/yael-maa/so_long/img_xpm/player_up.xpm", &w, &h);
	invalid_img_file(map, map->player_img,
		"Invalid player_img file or content\n");
	map->col_img = mlx_xpm_file_to_image(map->mlx,
			"/mnt/homes/yael-maa/so_long/img_xpm/coin.xpm", &w, &h);
	invalid_img_file(map, map->col_img, "Invalid col_img file or content\n");
}

void	put_img(t_map *map, int i, int j)
{
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
