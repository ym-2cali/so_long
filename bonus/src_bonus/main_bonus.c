/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 05:06:19 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 12:55:45 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	draw_img(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->arr[++i])
	{
		j = -1;
		while (map->arr[i][++j])
			put_img(map, i, j);
	}
}

void	lst_to_arr_helper(t_list *list, char **arr, t_node *tmp)
{
	int		i;
	int		j;

	i = 0;
	while (i < list->size - 1)
	{
		if (tmp->content[0] == '\n' || tmp->content[0] == '\0')
			break ;
		arr[i] = malloc(ft_strlen(tmp->content) + 1);
		if (!arr[i])
		{
			ft_freearr(arr);
			return ;
		}
		j = 0;
		while (tmp->content[j] && tmp->content[j] != '\n')
		{
			arr[i][j] = tmp->content[j];
			j++;
		}
		arr[i][j] = '\0';
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
}

char	**lst_to_arr(t_list *list)
{
	char	**arr;
	t_node	*tmp;

	if (!list || !list->head)
		return (NULL);
	arr = malloc(sizeof(char *) * (list->size) + 1);
	if (!arr)
		return (NULL);
	tmp = list->head;
	lst_to_arr_helper(list, arr, tmp);
	return (arr);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_list	list;

	if (ac != 2)
	{
		write(2, "Error : Invalid argument!\n", 27);
		return (0);
	}
	ft_bzero(&list, sizeof(t_list));
	ft_bzero(&map, sizeof(t_map));
	parse(av[1], &list);
	get_window(&map, &list);
	get_coin_position(&map);
	if (list.size)
		clear_list(&list);
	get_img(&map);
	draw_img(&map);
	mlx_loop_hook(map.mlx, move_coin, &map);
	mlx_loop_hook(map.mlx, enemy_move_algo, &map);
	mlx_hook(map.win, 2, 0, h_events, &map);
	mlx_hook(map.win, 17, 0, close_window, &map);
	mlx_loop(map.mlx);
	ft_freearr(map.arr);
	return (0);
}
