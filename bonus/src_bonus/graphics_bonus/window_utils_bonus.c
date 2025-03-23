/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:12:45 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 12:02:38 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

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

void	get_enemy_img(t_map *map)
{
	int	w;
	int	h;

	map->enemy_down_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/enemy_down.xpm", &w, &h);
	invalid_img_file(map, map->enemy_down_img,
		"Invalid enemy_img file or content\n");
	map->enemy_left_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/enemy_left.xpm", &w, &h);
	invalid_img_file(map, map->enemy_left_img,
		"Invalid enemy_img file or content\n");
	map->enemy_right_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/enemy_right.xpm", &w, &h);
	invalid_img_file(map, map->enemy_right_img,
		"Invalid enemy_img file or content\n");
	map->enemy_up_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/enemy_up.xpm", &w, &h);
	invalid_img_file(map, map->enemy_up_img,
		"Invalid enemy_img file or content\n");
}

void	get_player_image(t_map *map)
{
	int	w;
	int	h;

	map->player_left_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/player_left.xpm", &w, &h);
	invalid_img_file(map, map->player_left_img,
		"Invalid player_left_img file or content\n");
	map->player_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/player_up.xpm", &w, &h);
	invalid_img_file(map, map->player_img,
		"Invalid player_img file or content\n");
	map->player_down_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/player_down.xpm", &w, &h);
	invalid_img_file(map, map->player_down_img,
		"Invalid player_down_img file or content\n");
	map->player_right_img = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/player_right.xpm", &w, &h);
	invalid_img_file(map, map->player_right_img,
		"Invalid player_right_img file or content\n");
}

void	get_col_img(t_map *map)
{
	int	w;
	int	h;

	map->col_img[0] = (mlx_xpm_file_to_image(map->mlx,
				"./img_xpm/coin_1.xpm", &w, &h));
	invalid_img_file(map, map->col_img[0],
		"Invalid col_img file or content\n");
	map->col_img[1] = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/coin_2.xpm", &w, &h);
	invalid_img_file(map, map->col_img[1],
		"Invalid col_img file or content\n");
	map->col_img[2] = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/coin_3.xpm", &w, &h);
	invalid_img_file(map, map->col_img[2],
		"Invalid col_img file or content\n");
	map->col_img[3] = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/coin_4.xpm", &w, &h);
	invalid_img_file(map, map->col_img[3],
		"Invalid col_img file or content\n");
	map->col_img[4] = mlx_xpm_file_to_image(map->mlx,
			"./img_xpm/coin_5.xpm", &w, &h);
	invalid_img_file(map, map->col_img[4],
		"Invalid col_img file or content\n");
}
