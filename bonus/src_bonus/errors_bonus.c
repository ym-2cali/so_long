/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:25:33 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 12:59:57 by yael-maa         ###   ########.fr       */
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

void	destroy_img_helper(t_map *map)
{
	if (map->enemy_left_img)
		mlx_destroy_image(map->mlx, map->enemy_left_img);
	if (map->enemy_right_img)
		mlx_destroy_image(map->mlx, map->enemy_right_img);
	if (map->enemy_up_img)
		mlx_destroy_image(map->mlx, map->enemy_up_img);
	if (map->col_img[0])
		mlx_destroy_image(map->mlx, map->col_img[0]);
	if (map->col_img[1])
		mlx_destroy_image(map->mlx, map->col_img[1]);
	if (map->col_img[2])
		mlx_destroy_image(map->mlx, map->col_img[2]);
	if (map->col_img[3])
		mlx_destroy_image(map->mlx, map->col_img[3]);
	if (map->col_img[4])
		mlx_destroy_image(map->mlx, map->col_img[4]);
}

void	destroy_image(t_map *map)
{
	if (map->exit_img)
		mlx_destroy_image(map->mlx, map->exit_img);
	if (map->floor_img)
		mlx_destroy_image(map->mlx, map->floor_img);
	if (map->wall_img)
		mlx_destroy_image(map->mlx, map->wall_img);
	if (map->player_down_img)
		mlx_destroy_image(map->mlx, map->player_down_img);
	if (map->player_img)
		mlx_destroy_image(map->mlx, map->player_img);
	if (map->player_left_img)
		mlx_destroy_image(map->mlx, map->player_left_img);
	if (map->player_right_img)
		mlx_destroy_image(map->mlx, map->player_right_img);
	if (map->enemy_down_img)
		mlx_destroy_image(map->mlx, map->enemy_down_img);
	destroy_img_helper(map);
}

void	read_error(t_list *list)
{
	perror("Can't open file");
	clear_list(list);
	exit(0);
}
