#include "../inc/so_long.h"

void    clear_list(t_list *list)
{
    t_node  *tmp;

    while (list->head)
    {
        tmp = list->head;
        list->head = list->head->next;
        free(tmp->content);
        free(tmp);
    }
}

void    read_map(char *av, t_list *list)
{
    int     fd;
    char    *str;
	int		i;

    if (!av)
        simple_error(list);
    if (!validate_extension(av))
        invalid_map(list);
    fd = open(av, O_RDONLY, 0777);
    if (fd < 0)
    {
        perror("Can't open file");
        exit(0);
    }
    str = NULL;
	i = 0;
    while (i == 0 || str != NULL)
    {
        str = get_next_line(fd);

        if (!str || (i == 0 && str[0] == '\n')) // ft_strncmp("\n", str, 1) == 0 
			return close(fd),free(str);
        i = 1;
        fill_list(list, create_node(str));
    }
    close(fd);
}

void    parse(char *av, t_list *list)
{
    read_map(av, list);
    if (!validate_map(list))
		invalid_map(list);
	printf("all good\n");
}

void    print_list(t_list *lst)
{
    t_node *tmp;

    tmp = lst->head;
    while (tmp)
    {
        printf("content = %s\n", tmp->content);
        tmp = tmp->next;
    }
}