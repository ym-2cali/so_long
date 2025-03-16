#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../parse/get_next_line/get_next_line.h"
# include "mlx.h"

typedef struct s_node {
    char          *content;
    struct s_node *next;
} t_node ;

typedef struct s_list {
    t_node  *head;
    t_node  *tail;
    int     size;
} t_list ;

typedef struct s_pos {
    int x;
    int y;    
} t_pos ;

typedef struct s_map {
    char    **arr;
    void    *mlx;
    void    *win;
    void    *player_img;
    void    *floor_img;
    void    *wall_img;
    void    *exit_img;
    void    *col_img;
    int     height;
    int     width;
    int     col;
    int     gain;
    t_pos   player_pos;
} t_map;

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
int     validate_map_content(t_list *list);
void    read_map(char *av, t_list *list);
int     count_elements(t_list *map, char c);
int	    validate_elements(t_list *list);
int	    check_form(t_list *map);
int     validate_map(t_list *list);
void    clear_list(t_list *list);
void    simple_error(t_list *list);
void    invalid_map(t_list *map);
void	ft_bzero(void *s, int n);
void    parse(char *av, t_list *list);
void    print_list(t_list *lst);
char	**lst_to_arr(t_list *list);
void	get_img(t_map *map);
void	draw_img(t_map *map);
int     get_height(t_map *map);
int     h_events(int keycode, t_map *map);
char	**ft_freearr(char **arr);
void    get_window(t_map *map, t_list *list);
void	move_up(t_map *map);
void	move_left(t_map *map);
void	move_down(t_map *map);
void	move_right(t_map *map);
int	    validate_size(t_list *list);
int	    close_window(t_map *map);
void    put_str(char *s, int fd);
void    invalid_img_file(t_map *map, void *param, char *s);

#endif