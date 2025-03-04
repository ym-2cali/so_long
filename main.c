#include "inc/so_long.h"

int	main(int ac, char **av)
{
    t_list  list;

    if (ac != 2)
        return (0);
    ft_bzero(&list, sizeof(t_list));
    parse(av[1], &list);
    if (list.size)
        clear_map(&list);
    return (0);
}
