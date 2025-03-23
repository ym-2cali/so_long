/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:05:11 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 05:21:37 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	clear_list(t_list *list)
{
	t_node	*tmp;

	while (list->head)
	{
		tmp = list->head;
		list->head = list->head->next;
		free(tmp->content);
		free(tmp);
	}
}

void	read_map(char *av, t_list *list)
{
	int		fd;
	char	*str;
	int		i;

	if (!av)
		simple_error(list);
	if (!validate_extension(av))
		invalid_map(list);
	fd = open(av, O_RDONLY, 0777);
	if (fd < 0)
	{
		perror("Can't open file");
		clear_list(list);
		exit(0);
	}
	str = NULL;
	i = 0;
	while (i == 0 || str != NULL)
	{
		str = get_next_line(fd);
		if (!str || (i == 0 && str[0] == '\n'))
			return (close(fd), free(str));
		i = 1;
		fill_list(list, create_node(str));
	}
	close(fd);
}

void	parse(char *av, t_list *list)
{
	read_map(av, list);
	if (!validate_map(list))
		invalid_map(list);
}
