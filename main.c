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
	while (i < list->size && tmp)
	{
		arr[i] = malloc(ft_strlen(tmp->content));
		if (!arr[i])
			return (NULL);
		j = 0;
		while (tmp->content[j])
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

// void	fill_data(t_list *list, t_data *data)
// {
// 	data->map = lst_to_arr(list);

// }

void draw_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			mlx_put_image_to_window(data->mlx, data->win, data->empty_img, j * 40, i * 40);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall_img, j * 40, i * 40);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->exit_img, j * 40, i * 40);
			else if (data->map[i][j] == 'P')
			{
				data->pos.x = j;
				data->pos.y = i;
				data->map[i][j] = '0';
				mlx_put_image_to_window(data->mlx, data->win, data->player_img, j * 40, i * 40);
			}
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->col_img, j * 40, i * 40);
			j++;
		}
		i++;
	}

}

int count_height(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}


int handle_move(int key, void *d)
{
	t_data *data = (t_data *)d;
	(void)data;
	if (key == 53)
		exit(1);
	else if (key == 13)
	{
		printf("%d|%d|%c\n", data->pos.x, data->pos.y, data->map[data->pos.y][data->pos.x] );
		if (data->map[data->pos.y - 1][data->pos.x] != '1')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->empty_img, data->pos.x * 40, data->pos.y * 40);
			data->pos.y--;
			mlx_put_image_to_window(data->mlx, data->win, data->player_img, data->pos.x * 40, data->pos.y * 40);
		}
	}
	else if (key == 0)
	{
		if (data->map[data->pos.y][data->pos.x - 1] != '1')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->empty_img, data->pos.x * 40, data->pos.y * 40);
			data->pos.x--;
			mlx_put_image_to_window(data->mlx, data->win, data->player_img, data->pos.x * 40, data->pos.y * 40);
		}
	}
	else if (key == 1)
	{
		if (data->map[data->pos.y + 1][data->pos.x] != '1')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->empty_img, data->pos.x * 40, data->pos.y * 40);
			data->pos.y++;
			mlx_put_image_to_window(data->mlx, data->win, data->player_img, data->pos.x * 40, data->pos.y * 40);
		}
	}
	else if (key == 2)
	{
		if (data->map[data->pos.y][data->pos.x + 1] != '1')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->empty_img, data->pos.x * 40, data->pos.y * 40);
			data->pos.x++;
			mlx_put_image_to_window(data->mlx, data->win, data->player_img, data->pos.x * 40, data->pos.y * 40);
		}
	}
	return 1;
}


int	main(int ac, char **av)
{
    t_data data;
    t_list  list;

    if (ac != 2)
        return (0);
    ft_bzero(&list, sizeof(t_list));
    parse(av[1], &list);
	data.map =  lst_to_arr(&list);
	if (!data.map)
		return (clear_map(&list), 0);
	int i = 0;
	data.width = ft_strlen(data.map[0]) - 1;
	data.height = count_height(data.map);
	while (data.map[i])
	{
		printf("%s", data.map[i]);
		i++;
	}
    if (list.size)
        clear_map(&list);
    int w, h;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, data.width * 40, data.height * 40, "So_long");
    data.player_img = mlx_xpm_file_to_image(data.mlx, "player.xpm",&w, &h);
    data.empty_img = mlx_xpm_file_to_image(data.mlx, "floor.xpm",&w, &h);
    data.wall_img = mlx_xpm_file_to_image(data.mlx, "wall.xpm",&w, &h);
    data.col_img = mlx_xpm_file_to_image(data.mlx, "coin.xpm",&w, &h);
	data.exit_img = mlx_xpm_file_to_image(data.mlx, "exit.xpm",&w, &h);
	draw_map(&data);
	mlx_key_hook(data.win, handle_move, &data);
    mlx_loop(data.mlx);
    return (0);
}
