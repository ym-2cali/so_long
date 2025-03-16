/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:44:41 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/16 04:45:05 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void    get_positions(t_list *list, t_pos *pos, t_pos *size, char c)
{
    char    **map;
    int     i;
    int     j;
    
    map = lst_to_arr(list);
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][i] == c)
            {
                pos->x = j;
                pos->y = i;
            }
            j++;
        }
        i++;
    }
    size->x = j;
    size->y = i;
    ft_freearr(map);
}

void    fill(char **map, t_pos size, t_pos current)
{
    if ((current.y < 0) || (current.x < 0) || (current.y >= size.y) || (current.x >= size.x)
        || map[current.y][current.x] == '1')
        return ;
    map[current.y][current.x] == 'X';
    fill(map, size, (t_pos){current.x - 1, current.y});
    fill(map, size, (t_pos){current.x + 1, current.y});
    fill(map, size, (t_pos){current.x, current.y - 1});
    fill(map, size, (t_pos){current.x, current.y + 1});
}

void    flood_fill(char **map, t_pos size, t_pos begin)
{
    fill(map, size, begin);
}

int validate_path(t_list *list)
{
    t_pos   player_pos;
    t_pos   size;
    char    **map;

    get_positions(list, &player_pos, &size, 'P');
    map = lst_to_arr(list);
    flood_fill(map, size, player_pos);
}