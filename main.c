/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:26:44 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/16 22:00:36 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include "mlx.h"

void    ft()
{
    system("leaks so_long");
}

char	**lst_to_arr(t_list *list)
{
	char	**arr;
	int		i;
	int		j;
	t_node	*tmp;

	if (!list || !list->head)
		return (NULL);
	arr = malloc(sizeof(char *) * (list->size));
	if (!arr)
		return (NULL);
	i = 0;
	tmp = list->head;
	while (i < list->size - 1)
	{
		if (tmp->content[0] == '\n' || tmp->content[0] == '\0')
			break ;
		arr[i] = malloc(ft_strlen(tmp->content));
		if (!arr[i])	
			return (ft_freearr(arr));
		j = 0;
		while (tmp->content[j] != '\n')
		{
			arr[i][j] = tmp->content[j];
			j++;
		}
		arr[i][j] = '\0';
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}

void leaks_handler()
{
	system("lsof -h -p  so_long");
}
int	main(int ac, char **av)
{
	t_map	map;
    t_list  list;

	// atexit(leaks_handler);
    if (ac != 2)
        return (0);
    ft_bzero(&list, sizeof(t_list));
	ft_bzero(&map, sizeof(t_map));
    parse(av[1], &list);
	get_window(&map, &list);
    if (list.size)
        clear_list(&list);
	get_img(&map);
	draw_img(&map);
	mlx_key_hook(map.win, h_events, &map);
	mlx_hook(map.win, 17, 0, close_window, &map);
	mlx_loop(&map.mlx);
	ft_freearr(map.arr);
    return (0);
}
