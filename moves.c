/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:05:09 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/15 21:03:46 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	move_up(t_map *map)
{
	if (map->arr[map->player_pos.y - 1][map->player_pos.x]  != '1')
	{
		if (map->arr[map->player_pos.y - 1][map->player_pos.x]  == 'C')
		{
			map->gain++;
			mlx_put_image_to_window(map->mlx, map->win, map->floor_img, map->player_pos.x * 100, map->player_pos.y * 100);
			map->player_pos.y--;
			mlx_put_image_to_window(map->mlx, map->win, map->player_img, map->player_pos.x * 100, map->player_pos.y * 100);
		}
		else if (map->arr[map->player_pos.y - 1][map->player_pos.x]  == 'E')
		{
			if (map->col == map->gain)
			{
				ft_freearr(map->arr);
				write(1, "you won\n", 9);
				exit(0);
			}
		}
		else
		{
			mlx_put_image_to_window(map->mlx, map->win, map->floor_img, map->player_pos.x * 100, map->player_pos.y * 100);
			map->player_pos.y--;
			mlx_put_image_to_window(map->mlx, map->win, map->player_img, map->player_pos.x * 100, map->player_pos.y * 100);
		}
	}
}

void	move_left(t_map *map)
{
	if (map->arr[map->player_pos.y][map->player_pos.x - 1]  != '1')
	{
		if (map->arr[map->player_pos.y][map->player_pos.x - 1]  == 'C')
		{
			map->gain++;
			mlx_put_image_to_window(map->mlx, map->win, map->floor_img, map->player_pos.x * 100, map->player_pos.y * 100);
			map->player_pos.x--;
			mlx_put_image_to_window(map->mlx, map->win, map->player_img, map->player_pos.x * 100, map->player_pos.y * 100);
		}
		else if (map->arr[map->player_pos.y][map->player_pos.x - 1]  == 'E')
		{
			if (map->col == map->gain)
			{
				ft_freearr(map->arr);
				write(1, "you won\n", 9);
				exit(0);
			}
		}
		else
		{
			mlx_put_image_to_window(map->mlx, map->win, map->floor_img, map->player_pos.x * 100, map->player_pos.y * 100);	
			map->player_pos.x--;
			mlx_put_image_to_window(map->mlx, map->win, map->player_img, map->player_pos.x * 100, map->player_pos.y * 100);
		}
	}
}

void	move_down(t_map *map)
{
	if (map->arr[map->player_pos.y + 1][map->player_pos.x]  != '1')
	{
		if (map->arr[map->player_pos.y + 1][map->player_pos.x]  == 'C')
		{
			map->gain++;
			mlx_put_image_to_window(map->mlx, map->win, map->floor_img, map->player_pos.x * 100, map->player_pos.y * 100);
			map->player_pos.y++;
			mlx_put_image_to_window(map->mlx, map->win, map->player_img, map->player_pos.x * 100, map->player_pos.y * 100);
		}
		else if (map->arr[map->player_pos.y + 1][map->player_pos.x]  == 'E')
		{
			if (map->col == map->gain)
			{
				ft_freearr(map->arr);
				write(1, "you won\n", 9);
				exit(0);
			}
		}
		else
		{
			mlx_put_image_to_window(map->mlx, map->win, map->floor_img, map->player_pos.x * 100, map->player_pos.y * 100);
			map->player_pos.y++;	
			mlx_put_image_to_window(map->mlx, map->win, map->player_img, map->player_pos.x * 100, map->player_pos.y * 100);
		}
	}
}

void	move_right(t_map *map)
{
	if (map->arr[map->player_pos.y][map->player_pos.x + 1]  != '1')
	{
		if (map->arr[map->player_pos.y ][map->player_pos.x + 1]  == 'C')
		{
			map->gain++;
			mlx_put_image_to_window(map->mlx, map->win, map->floor_img, map->player_pos.x * 100, map->player_pos.y * 100);
			map->player_pos.x++;
			mlx_put_image_to_window(map->mlx, map->win, map->player_img, map->player_pos.x * 100, map->player_pos.y * 100);
		}
		else if (map->arr[map->player_pos.y - 1][map->player_pos.x]  == 'E')
		{
			if (map->col == map->gain)
			{
				ft_freearr(map->arr);
				write(1, "you won\n", 9);
				exit(0);
			}
		}
		else
		{
			mlx_put_image_to_window(map->mlx, map->win, map->floor_img, map->player_pos.x * 100, map->player_pos.y * 100);		
			map->player_pos.x++;
			mlx_put_image_to_window(map->mlx, map->win, map->player_img, map->player_pos.x * 100, map->player_pos.y * 100);
		}
	}
}
