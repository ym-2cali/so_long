/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:05:09 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/24 16:50:45 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

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
			else
				return ;
		}
		else
			put_player_img_up(map);
		display_moves(map);
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
			else
				return ;
		}
		else
			put_player_img_left(map);
		display_moves(map);
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
			else
				return ;
		}
		else
			put_player_img_down(map);
		display_moves(map);
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
			else
				return ;
		}
		else
			put_player_img_right(map);
		display_moves(map);
	}
}
