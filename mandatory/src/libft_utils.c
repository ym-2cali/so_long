/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:30:11 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 11:03:38 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**ft_freearr(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (NULL);
}

void	put_str(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	r;

	if (fd < 0)
		return ;
	r = n;
	if (r < 0)
	{
		write(fd, "-", 1);
		r = -r;
	}
	if (r >= 0 && r <= 9)
	{
		ft_putchar_fd(r + '0', fd);
	}
	else
	{
		ft_putnbr_fd(r / 10, fd);
		ft_putnbr_fd(r % 10, fd);
	}
}

void	display_moves(t_map *map)
{
	write(1, "move: ", 6);
	ft_putnbr_fd(++map->moves, 1);
	write(1, "\n", 1);
}
