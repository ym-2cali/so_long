/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:08:54 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/20 08:20:16 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	enemy_direction(t_map *map)
{
	int	x;
	int	y;
	struct timeval current_time;
	struct timeval time_dif;
	
	x = map->enemy_pos.x - map->player_pos.x;
	y = map->enemy_pos.y - map->player_pos.y;
	printf("%d %d", x, y);
	gettimeofday(&current_time, NULL);
	time_dif.tv_sec = (current_time.tv_sec - map->last_move_time.tv_sec) * 1000000 + (current_time.tv_usec - map->last_move_time.tv_usec);
	if (x == 0 && y == 0)
	{
		write(1, "you lost\n", 10);
		exit(0);
	}
	if (time_dif.tv_sec >= 1000000)
	{
		if (x >= 0)
		{
			if (y >= 0)
			{
				if (x > y && map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != 'E')	
					move_enemy_left(map);
				else if (x < y && map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != 'E')
					move_enemy_up(map);
				else
				{
					if (map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != 'E')
						move_enemy_right(map);
					else if (map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != 'E')
						move_enemy_up(map);
					else if (map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != 'E')
						move_enemy_left(map);
					else if (map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != 'E')
						move_enemy_down(map);
				}
			}
			else if (y < 0 && map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y - 1][map->enemy_pos.x - 1] != 'E')
				move_enemy_up(map);
			else
			{
				if (map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != 'E')
					move_enemy_right(map);
				else if (map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != 'E')
					move_enemy_up(map);
				else if (map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != 'E')
					move_enemy_left(map);
				else if (map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != 'E')
					move_enemy_down(map);
			}
		}
		else if (x <= 0)
		{
			if (y >= 0 && map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != 'E')
				move_enemy_right(map);
			else if (y <= 0)
			{
				if (y >= x && map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != 'E')
					move_enemy_down(map);
				else if (y <= x && map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != 'E')
					move_enemy_right(map);
				else
				{
					if (map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != 'E')
						move_enemy_right(map);
					else if (map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != 'E')
						move_enemy_up(map);
					else if (map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != 'E')
						move_enemy_left(map);
					else if (map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != 'E')
						move_enemy_down(map);
				}
			}
			else
			{
				if (map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != 'E')
					move_enemy_right(map);
				else if (map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != 'E')
					move_enemy_up(map);
				else if (map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != 'E')
					move_enemy_left(map);
				else if (map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != 'E')
					move_enemy_down(map);
			}
		}
		map->last_move_time = current_time;
	}
}

int	enemy_move_algo(t_map *map)
{
	// while (map->mlx)
	enemy_direction(map);
	// sleep(1);
	// draw_img(map);
	return (0);
}