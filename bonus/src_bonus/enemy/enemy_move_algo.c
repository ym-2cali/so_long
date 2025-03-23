/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:08:54 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 13:15:40 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	enemy_direction_helper2(t_map *map, int x, int y)
{
	if (((map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != '1'
			&& map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != 'E')
			&& (((x >= 0) && ((-y) >= x)) || ((x <= 0) && x > y)))
		|| ((map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] == '1'
			|| map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] == 'E')
			&& (((x >= y) && (y >= 0))
			|| ((y <= 0) && x >= (-y))))
		|| ((map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] == '1'
			|| map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] == 'E')
			&& ((((-x) >= y) && (y >= 0))
			|| ((y <= 0) && x <= y))))
		move_enemy_down(map);
	else if (((map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != '1'
			&& map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != 'E')
			&& (((x >= y) && (y >= 0)) || ((y <= 0) && x > (-y))
			|| ((x == y) && y > 0)))
		|| ((map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] == '1'
			|| map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] == 'E')
			&& (((x >= 0) && (y > x))
			|| ((x <= 0) && (-x) <= y)))
		|| ((map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] == '1'
			|| map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] == 'E')
			&& (((x > 0) && ((-y) >= x)) || ((x <= 0) && x <= y))))
		move_enemy_left(map);
}

void	enemy_direction_helper1(t_map *map, int x, int y)
{
	if (((map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != '1'
			&& map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != 'E')
			&& (((x >= 0) && (y >= x)) || ((x <= 0) && (-x) <= y)))
		|| ((map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] == '1'
			|| map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] == 'E')
			&& (((x >= y) && (y >= 0)) || ((y <= 0) && x > (-y))))
		|| ((map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] == '1'
			|| map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] == 'E')
			&& ((((-x) >= y) && (y >= 0)) || ((y <= 0) && x <= y))))
		move_enemy_up(map);
	else if (((map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != '1'
			&& map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != 'E')
			&& ((((-x) >= y) && (y >= 0)) || ((y <= 0) && x < y)
			|| ((x == y && y < 0) && !((x == y) && y > 0))))
		|| ((map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] == '1'
			|| map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] == 'E' )
			&& ((y < 0 && x <= 0 && (-x) <= (-y)) || (y == 0 && x < 0))))
		move_enemy_right(map);
	else
		enemy_direction_helper2(map, x, y);
}

void	enemy_direction(t_map *map)
{
	int				x;
	int				y;
	struct timeval	current_time;
	struct timeval	time_dif;

	x = map->enemy_pos.x - map->player_pos.x;
	y = map->enemy_pos.y - map->player_pos.y;
	gettimeofday(&current_time, NULL);
	time_dif.tv_sec = (current_time.tv_sec - map->last_move_time.tv_sec)
		* 1000000 + (current_time.tv_usec - map->last_move_time.tv_usec);
	if (x == 0 && y == 0)
	{
		write(1, "you lost\n", 10);
		exit(0);
	}
	if (time_dif.tv_sec >= (1000000 / 2))
	{
		enemy_direction_helper1(map, x, y);
		map->last_move_time = current_time;
	}
}

int	enemy_move_algo(t_map *map)
{
	move_coin(map);
	enemy_direction(map);
	return (0);
}
