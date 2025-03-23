/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:41:28 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 13:20:55 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	get_coin_position(t_map *map)
{
	int	len;
	int	height;

	height = get_height(map) - 1;
	while (height >= 0)
	{
		len = ft_strlen(map->arr[0]) - 1;
		while (len >= 0)
		{
			if (map->arr[height][len] == 'C')
			{
				map->col_last_pos.x = len;
				map->col_last_pos.y = height;
				return ;
			}
			len--;
		}
		height--;
	}
}

void	put_frames(t_map *map, int i, int j)
{
	if (map->coin_f == 0)
		coin_frame1(map, i, j);
	else if (map->coin_f == 1)
		coin_frame2(map, i, j);
	else if (map->coin_f == 2)
		coin_frame3(map, i, j);
	else if (map->coin_f == 3)
		coin_frame4(map, i, j);
	else if (map->coin_f == 4)
		coin_frame0(map, i, j);
}

void	put_coin_frames(t_map *map)
{
	struct timeval	current_time;
	struct timeval	time_dif;
	int				i;
	int				j;

	get_coin_position(map);
	gettimeofday(&current_time, NULL);
	time_dif.tv_sec
		= (current_time.tv_sec - map->coin_move_time.tv_sec) * 1000000
		+ (current_time.tv_usec - map->coin_move_time.tv_usec);
	if (time_dif.tv_sec >= (1000000 / 4))
	{
		i = -1;
		while ((++i) <= map->col_last_pos.y)
		{
			j = 0;
			while (j <= map->col_last_pos.x)
			{
				if (map->arr[i][j] == 'C')
					put_frames(map, i, j);
				j++;
			}
		}
		map->coin_move_time = current_time;
	}
}

int	move_coin(t_map *map)
{
	put_coin_frames(map);
	return (0);
}
