#include "../../inc/so_long.h"

void    invalid_map(t_list *map)
{
    write(2, "Invalid Map\n", 12);
    clear_map(map);
    exit(1);
}

void    error_file(t_list *list)
{
    perror("Can't open file");
    if (list->size)
        clear_map(list);
    exit(1);
}

void    simple_error(t_list *list)
{
    write(2, "Error\n", 7);
    if (list->size)
        clear_map(list);
    exit(1);
}