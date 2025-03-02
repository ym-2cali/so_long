#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../parse/get_next_line/get_next_line.h"

typedef struct s_node {
    char          *content;
    struct s_node *next;
} t_node ;

typedef struct s_list {
    t_node  *head;
    t_node  *tail;
    int     size;
} t_list ;

int     ft_strlen(const char *s);
int	    ft_strncmp(const char *s1, const char *s2, int n);
int     validate_extension(char *av);
t_node	*create_node(char *content);
void	fill_list(t_list *list, t_node *node);
int     validate_borders(t_list *list);
int     validate_sides(char *av);
int     up_down(t_list *list);
int     map_comp(char c);
int     line_comp(char *av);
int     validate_content(t_list *list);
int     validate_map(t_list *list);

#endif