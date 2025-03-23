/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_frames.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:24:15 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 13:20:59 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	coin_frame1(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->win,
		map->floor_img, j * 100, i * 100);
	mlx_put_image_to_window(map->mlx, map->win,
		map->col_img[1], j * 100, i * 100);
	if (i == map->col_last_pos.y
		&& j == map->col_last_pos.x)
		map->coin_f = 1;
}

void	coin_frame2(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->win,
		map->floor_img, j * 100, i * 100);
	mlx_put_image_to_window(map->mlx, map->win,
		map->col_img[2], j * 100, i * 100);
	if (i == map->col_last_pos.y
		&& j == map->col_last_pos.x)
		map->coin_f = 2;
}

void	coin_frame3(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->win,
		map->floor_img, j * 100, i * 100);
	mlx_put_image_to_window(map->mlx, map->win,
		map->col_img[3], j * 100, i * 100);
	if (i == map->col_last_pos.y
		&& j == map->col_last_pos.x)
		map->coin_f = 3;
}

void	coin_frame4(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->win,
		map->floor_img, j * 100, i * 100);
	mlx_put_image_to_window(map->mlx, map->win,
		map->col_img[4], j * 100, i * 100);
	if (i == map->col_last_pos.y
		&& j == map->col_last_pos.x)
		map->coin_f = 4;
}

void	coin_frame0(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->win,
		map->floor_img, j * 100, i * 100);
	mlx_put_image_to_window(map->mlx, map->win,
		map->col_img[0], j * 100, i * 100);
	if (i == map->col_last_pos.y
		&& j == map->col_last_pos.x)
		map->coin_f = 0;
}
