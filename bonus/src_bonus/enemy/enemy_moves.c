/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:46:58 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/20 03:09:39 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void    move_enemy_up(t_map *map)
{
    if (map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y - 1][map->enemy_pos.x] != 'E')
	{
		map->arr[map->player_pos.y][map->player_pos.x] = '0'; 	
		put_enemy_img_up(map);
    }
}

void    move_enemy_left(t_map *map)
{
    if (map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x - 1] != 'E')
	{
		map->arr[map->player_pos.y][map->player_pos.x] = '0'; 	
		put_enemy_img_left(map);
    }
}

void    move_enemy_down(t_map *map)
{
    if (map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != '1' && map->arr[map->enemy_pos.y + 1][map->enemy_pos.x] != 'E')
	{
		map->arr[map->player_pos.y][map->player_pos.x] = '0'; 	
		put_enemy_img_down(map);
    }
}

void    move_enemy_right(t_map *map)
{
    if (map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != '1' && map->arr[map->enemy_pos.y][map->enemy_pos.x + 1] != 'E')
	{
		map->arr[map->player_pos.y][map->player_pos.x] = '0'; 	
		put_enemy_img_right(map);
    }
}
