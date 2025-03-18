/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:14:19 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/18 02:53:00 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	invalid_map(t_list *map)
{
	write(2, "Invalid Map\n", 12);
	clear_list(map);
	exit(1);
}

void	error_file(t_list *list)
{
	perror("Can't open file");
	if (list->size)
		clear_list(list);
	exit(1);
}

void	simple_error(t_list *list)
{
	write(2, "Error\n", 7);
	if (list->size)
		clear_list(list);
	exit(1);
}
