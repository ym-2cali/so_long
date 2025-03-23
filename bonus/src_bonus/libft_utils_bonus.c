/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:30:11 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 13:01:14 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

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

int	ft_ilen(int n)
{
	long long int	c;
	int				size;

	c = n;
	size = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		size = 1;
	while (c)
	{
		c /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long	m;
	char		*s;
	int			len;

	m = n;
	len = ft_ilen(m);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	len--;
	if (n < 0)
		m *= -1;
	while (len >= 0)
	{
		s[len] = m % 10 + 48;
		m /= 10;
		len--;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}

void	display_moves(t_map *map)
{
	char	*nbr;

	nbr = ft_itoa(++map->move);
	mlx_put_image_to_window(map->mlx, map->win, map->wall_img, 0, 0);
	mlx_string_put(map->mlx, map->win, 10, 10, 0x00FF0000, nbr);
	free(nbr);
}
