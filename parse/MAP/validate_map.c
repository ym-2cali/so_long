#include "../../inc/so_long.h"

int map_comp(char c)
{
    return (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == '\n');
}

int line_comp(char *av)
{
    int i;

    i = 0;
    while (av[i])
    {
        if (!map_comp(av[i]))
            return (0);
        i++;
    }
    return (1);
}

int validate_content(t_list *list)
{
    t_node  *tmp;

    tmp = list->head;
    while (tmp)
    {
        if (!line_comp(tmp->content))
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int validate_map_content(t_list *list)
{
    if (!validate_borders(list) || !validate_content(list) 
        || !validate_elements(list) || !validate_path(list))
        return (0);
    return (1);
}

int validate_map(t_list *list)
{
    if (!list)
    {
        write(2, "Memory Problem\n", 16);
        exit(0);
    }
    if (!list->head)
        invalid_map(list);
    if (!validate_map_content(list) || !check_form(list) || !validate_size(list))
    {
        // printf("%d\n", validate_size(list));
        // printf("%d\n", validate_map_content(list));
        // printf("%d\n", check_form(list));
        return (0);
    }   
    return (1);
}