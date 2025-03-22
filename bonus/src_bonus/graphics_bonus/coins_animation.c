/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:41:28 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/22 09:57:20 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"
 
void get_coin_position(t_map *map)
{
    int len;
    int height;
    
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

void    put_coin_frames(t_map *map)
{
    struct timeval current_time;
    struct timeval time_dif;
    int i;
    int j;

    get_coin_position(map);
    // printf("%d\n", map->col_last_pos.x);
    gettimeofday(&current_time, NULL);
    time_dif.tv_sec = (current_time.tv_sec - map->coin_move_time.tv_sec) * 1000000 + (current_time.tv_usec - map->coin_move_time.tv_usec);
    if (time_dif.tv_sec >= (1000000 / 4))
    {
        i = 0;
        while (i <= map->col_last_pos.y)
        {   
            j = 0;
            while (j <= map->col_last_pos.x)
            {
                if (map->arr[i][j] == 'C')
                {
                    if (map->coin_f == 0)
                    {
                        mlx_put_image_to_window(map->mlx, map->win,
		            	    map->floor_img, j * 100, i * 100);
                        mlx_put_image_to_window(map->mlx, map->win,
		            	    map->col_img[1], j * 100, i * 100);
                        if (i == map->col_last_pos.y && j == map->col_last_pos.x)
                            map->coin_f = 1;
                    }
                    else if (map->coin_f == 1)
                    {
            
                        mlx_put_image_to_window(map->mlx, map->win,
		            	    map->floor_img, j * 100, i * 100);
                        mlx_put_image_to_window(map->mlx, map->win,
		            	    map->col_img[2], j * 100, i * 100);
                        if (i == map->col_last_pos.y && j == map->col_last_pos.x)
                            map->coin_f = 2;            
                    }
                    else if (map->coin_f == 2)
                    {
                        mlx_put_image_to_window(map->mlx, map->win,
		            	    map->floor_img, j * 100, i * 100);
                        mlx_put_image_to_window(map->mlx, map->win,
		            	    map->col_img[3], j * 100, i * 100);
                        if (i == map->col_last_pos.y && j == map->col_last_pos.x)
                            map->coin_f = 3;
                    }
                    else if (map->coin_f == 3)
                    {
                        mlx_put_image_to_window(map->mlx, map->win,
		            	    map->floor_img, j * 100, i * 100);
                        mlx_put_image_to_window(map->mlx, map->win,
		            	    map->col_img[4], j * 100, i * 100);
                        if (i == map->col_last_pos.y && j == map->col_last_pos.x)
                            map->coin_f = 4;
                    }
                    else if (map->coin_f == 4)
                    {
                        mlx_put_image_to_window(map->mlx, map->win,
		            	    map->floor_img, j * 100, i * 100);
                        mlx_put_image_to_window(map->mlx, map->win,
		            	    map->col_img[0], j * 100, i * 100);
                        if (i == map->col_last_pos.y && j == map->col_last_pos.x)
                            map->coin_f = 0;
                    }
                }
                j++;
            }
            i++;
        }
        map->coin_move_time = current_time;
    }

}

int move_coin(t_map *map)
{
    put_coin_frames(map);
    return (0);
}