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
        perror("Can't open file");
    str = NULL;
	i = 0;
    while (i == 0 || str != NULL)
    {
        i = 1;
        // if (str)
        //     free (str);
		i = 1;
        str = get_next_line(fd);
        if (!str)
		{
            // simple_error(list);
			break ;
			// return ;
		}
        fill_list(list, create_node(str));
    }
    close(fd);
}

void    parse(char *av, t_list *list)
{
    read_map(av, list);
    // print_list(list);
    if (!validate_map(list))
	{
		invalid_map(list);
	}
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