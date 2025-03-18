/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:17:53 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/18 02:51:28 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

int	validate_extension(char *av)
{
	int	len;

	len = ft_strlen(av) - 4;
	if (len > 0 && av[len] == '.' && av[len + 1] == 'b'
		&& av[len + 2] == 'e' && av[len + 3] == 'r')
		return (1);
	return (0);
}
