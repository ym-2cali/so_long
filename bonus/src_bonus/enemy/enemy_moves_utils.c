/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:52:53 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/21 13:19:02 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	put_enemy_img_up(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
	map->arr[map->enemy_pos.y][map->enemy_pos.x] = '0'; 
	map->enemy_pos.y--;
	map->arr[map->enemy_pos.y][map->enemy_pos.x] = 'N';
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
	mlx_put_image_to_window(map->mlx, map->win, map->enemy_up_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
}

void	put_enemy_img_left(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
	map->arr[map->enemy_pos.y][map->enemy_pos.x] = '0'; 
	map->enemy_pos.x--;
	map->arr[map->enemy_pos.y][map->enemy_pos.x] = 'N';
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
	mlx_put_image_to_window(map->mlx, map->win, map->enemy_left_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
}

void	put_enemy_img_down(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
	map->arr[map->enemy_pos.y][map->enemy_pos.x] = '0'; 
	map->enemy_pos.y++;
	map->arr[map->enemy_pos.y][map->enemy_pos.x] = 'N';
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
	mlx_put_image_to_window(map->mlx, map->win, map->enemy_down_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
}

void	put_enemy_img_right(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
	map->arr[map->enemy_pos.y][map->enemy_pos.x] = '0'; 
	map->enemy_pos.x++;
	map->arr[map->enemy_pos.y][map->enemy_pos.x] = 'N';
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
	mlx_put_image_to_window(map->mlx, map->win, map->enemy_right_img,
		map->enemy_pos.x * 100, map->enemy_pos.y * 100);
}