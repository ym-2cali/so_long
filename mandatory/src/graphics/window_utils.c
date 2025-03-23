/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:12:45 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 11:29:45 by yael-maa         ###   ########.fr       */
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

void	get_player_image(t_map *map)
{
	int	w;
	int	h;

	map->player_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/player_up.xpm", &w, &h);
	invalid_img_file(map, map->player_img,
		"Invalid player_up_img file or content\n");
	map->player_left_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/player_left.xpm", &w, &h);
	invalid_img_file(map, map->player_left_img,
		"Invalid player_left_img file or content\n");
	map->player_down_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/player_down.xpm", &w, &h);
	invalid_img_file(map, map->player_down_img,
		"Invalid player_down_img file or content\n");
	map->player_right_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/player_right.xpm", &w, &h);
	invalid_img_file(map, map->player_right_img,
		"Invalid player_right_img file or content\n");
}

void	get_img(t_map *map)
{
	int	w;
	int	h;

	map->exit_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/exit.xpm", &w, &h);
	invalid_img_file(map, map->exit_img, "Invalid exit_img file or content\n");
	map->floor_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/floor.xpm", &w, &h);
	invalid_img_file(map, map->floor_img,
		"Invalid floor_img file or content\n");
	map->wall_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/wall.xpm", &w, &h);
	invalid_img_file(map, map->wall_img, "Invalid wall_img file or content\n");
	map->col_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/coin.xpm", &w, &h);
	invalid_img_file(map, map->col_img, "Invalid col_img file or content\n");
	get_player_image(map);
}
