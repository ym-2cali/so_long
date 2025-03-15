/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:26:44 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/15 02:10:18 by yael-maa         ###   ########.fr       */
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
			return (NULL);
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

int	main(int ac, char **av)
{
	t_map	map;
    t_list  list;

    if (ac != 2)
        return (0);
    ft_bzero(&list, sizeof(t_list));
	ft_bzero(&map, sizeof(t_map));
    parse(av[1], &list);

	map.arr = lst_to_arr(&list);
	map.height = get_height(&map);
	map.width = ft_strlen(map.arr[0]);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width * 100, map.height * 100, "so_long");
	get_img(&map);
	draw_img(&map);
	mlx_key_hook(map.win, h_events, &map);
    if (list.size)
        clear_map(&list);
	mlx_loop(&map.mlx);
    return (0);
}
