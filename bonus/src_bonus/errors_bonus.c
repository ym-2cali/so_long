/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:25:33 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/18 06:21:08 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	invalid_img_file(t_map *map, void *param, char *s)
{
	if (!param)
	{
		put_str(s, 2);
		close_window(map);
	}
}
