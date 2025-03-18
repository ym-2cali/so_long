/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:20:37 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/18 05:27:00 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	put_player_img_up(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->player_pos.x * 100, map->player_pos.y * 100);
	map->player_pos.y--;
	mlx_put_image_to_window(map->mlx, map->win, map->player_img,
		map->player_pos.x * 100, map->player_pos.y * 100);
}

void	put_player_img_left(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->player_pos.x * 100, map->player_pos.y * 100);
	map->player_pos.x--;
	mlx_put_image_to_window(map->mlx, map->win, map->player_img,
		map->player_pos.x * 100, map->player_pos.y * 100);
}

void	put_player_img_down(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->player_pos.x * 100, map->player_pos.y * 100);
	map->player_pos.y++;
	mlx_put_image_to_window(map->mlx, map->win, map->player_img,
		map->player_pos.x * 100, map->player_pos.y * 100);
}

void	put_player_img_right(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->floor_img,
		map->player_pos.x * 100, map->player_pos.y * 100);
	map->player_pos.x++;
	mlx_put_image_to_window(map->mlx, map->win, map->player_img,
		map->player_pos.x * 100, map->player_pos.y * 100);
}
