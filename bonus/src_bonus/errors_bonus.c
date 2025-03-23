/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:25:33 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 05:27:41 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	invalid_img_file(t_map *map, void *param, char *s)
{
	if (!param)
	{
		put_str(s, 2);
		close_window(map);
	}
}
void	destroy_image(t_map *map)
{
	mlx_destroy_image(map->mlx, map->exit_img);
	mlx_destroy_image(map->mlx, map->floor_img);
	mlx_destroy_image(map->mlx, map->wall_img);
	mlx_destroy_image(map->mlx, map->player_down_img);
	mlx_destroy_image(map->mlx, map->player_img);
	mlx_destroy_image(map->mlx, map->player_left_img);
	mlx_destroy_image(map->mlx, map->player_right_img);
	mlx_destroy_image(map->mlx, map->enemy_down_img);
	mlx_destroy_image(map->mlx, map->enemy_left_img);
	mlx_destroy_image(map->mlx, map->enemy_right_img);
	mlx_destroy_image(map->mlx, map->enemy_up_img);
	mlx_destroy_image(map->mlx, map->col_img[0]);
	mlx_destroy_image(map->mlx, map->col_img[1]);
	mlx_destroy_image(map->mlx, map->col_img[2]);
	mlx_destroy_image(map->mlx, map->col_img[3]);
	mlx_destroy_image(map->mlx, map->col_img[4]);
}
