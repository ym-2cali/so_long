#include "../inc/so_long.h"

void    clear_map(t_list *list)
{
    t_node  *tmp;

    while (list->head)
    {
        tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }
}

void    read_map(char *av, t_list *list)
{
    int     fd;
    char    *str;

    if (!av)
        simple_error(list);
    if (!validate_extension(av))
        invalid_map(list);
    fd = open(av, O_RDONLY, 0777);
    if (fd < 0)
        perror("Can't open file");
    str = "";
    while (str)
    {
        str = get_next_line(fd);
        if (!str)
            simple_error(list);
        fill_list(list, create_node(str));
        free(str);
    }
    close(fd);
}

void    parse(char *av, t_list *list)
{
    read_map(av, list);
    if (!validate_map_content(list))
        invalid_map(list);
}