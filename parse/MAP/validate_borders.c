#include "../../inc/so_long.h"

int up_down(t_list *list)
{
    int i;

    i = 0;
    while (list->head->content[i])
    {
        if (list->head->content[i] != '1' || list->tail->content[i] != '1')
            return (0);
        i++;
    }
    return (1);
}

int validate_sides(char *av)
{
    int len;

    len = ft_strlen(av) - 1;
    if (av[0] == '1' && av[len] == '1')
        return (1);
    return (0);
}

int validate_borders(t_list *list)
{
    t_node  *tmp;

    tmp = list->head->next;
    while (tmp != NULL)
    {
        if (!validate_sides(tmp->content))
            return (0);
        tmp = tmp->next;
    }
    if (!up_down(list))
        return (0);
    return (1);
}