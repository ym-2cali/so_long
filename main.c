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
		arr[i] = malloc(strlen(tmp->content));
		if (!arr[i])
			return (NULL);
		j = 0;
		while (tmp->content[j])
		{
			arr[i][j] = tmp->content[j];
			j++;
		}
		i++;
		tmp = tmp->next;
	}
	return (arr);
}
int	main(int ac, char **av)
{
    t_data data;
    t_list  list;
	char	**arr;

    if (ac != 2)
        return (0);
    ft_bzero(&list, sizeof(t_list));
    parse(av[1], &list);
	data.map = lst_to_arr(&list);
	if (!arr)
		return (clear_map(&list), 0);
    if (list.size)
        clear_map(&list);
    // int w, h;
    // data.mlx = mlx_init();
    // data.win = mlx_new_window(data.mlx, 1000, 500, "Yahya");
    // data.player_img = mlx_xpm_file_to_image(data.mlx, "yahya.xpm",&w, &h);

    // mlx_loop(mlx);
    return (0);
}
