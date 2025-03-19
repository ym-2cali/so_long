/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:05:09 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/19 05:27:35 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	move_up(t_map *map)
{
	if (map->arr[map->player_pos.y - 1][map->player_pos.x] != '1')
	{
		if (map->arr[map->player_pos.y - 1][map->player_pos.x] == 'C')
		{
			map->gain++;
			map->arr[map->player_pos.y - 1][map->player_pos.x] = '0';
			put_player_img_up(map);
		}
		else if (map->arr[map->player_pos.y - 1][map->player_pos.x] == 'E')
		{
			if (map->col == map->gain)
			{
				write(1, "you won\n", 9);
				close_window(map);
			}
		}
		else
		{
			map->arr[map->player_pos.y][map->player_pos.x] = '0'; 	
			put_player_img_up(map);
		}
	}
}

void	move_left(t_map *map)
{
	if (map->arr[map->player_pos.y][map->player_pos.x - 1] != '1')
	{
		if (map->arr[map->player_pos.y][map->player_pos.x - 1] == 'C')
		{
			map->arr[map->player_pos.y][map->player_pos.x - 1] = '0';
			map->gain++;
			put_player_img_left(map);
		}
		else if (map->arr[map->player_pos.y][map->player_pos.x - 1] == 'E')
		{
			if (map->col == map->gain)
			{
				ft_freearr(map->arr);
				write(1, "you won\n", 9);
				exit(0);
			}
		}
		else
			put_player_img_left(map);
	}
}

void	move_down(t_map *map)
{
	if (map->arr[map->player_pos.y + 1][map->player_pos.x] != '1')
	{
		if (map->arr[map->player_pos.y + 1][map->player_pos.x] == 'C')
		{
			map->gain++;
			map->arr[map->player_pos.y + 1][map->player_pos.x] = '0';
			put_player_img_down(map);
		}
		else if (map->arr[map->player_pos.y + 1][map->player_pos.x] == 'E')
		{
			if (map->col == map->gain)
			{
				ft_freearr(map->arr);
				write(1, "you won\n", 9);
				exit(0);
			}
		}
		else
			put_player_img_down(map);
	}
}

void	move_right(t_map *map)
{
	if (map->arr[map->player_pos.y][map->player_pos.x + 1] != '1')
	{
		if (map->arr[map->player_pos.y][map->player_pos.x + 1] == 'C')
		{
			map->gain++;
			map->arr[map->player_pos.y][map->player_pos.x + 1] = '0';
			put_player_img_right(map);
		}
		else if (map->arr[map->player_pos.y][map->player_pos.x + 1] == 'E')
		{
			if (map->col == map->gain)
			{
				ft_freearr(map->arr);
				write(1, "you won\n", 9);
				exit(0);
			}
		}
		else
			put_player_img_right(map);
	}
}
