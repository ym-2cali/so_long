/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 04:46:56 by yael-maa          #+#    #+#             */
/*   Updated: 2025/03/23 13:14:03 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>
# include "../src_bonus/parse_bonus/get_next_line/get_next_line.h"
# include "mlx.h"

typedef struct s_node
{
	char			*content;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_list;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char			**arr;
	void			*mlx;
	void			*win;
	void			*player_img;
	void			*player_left_img;
	void			*player_down_img;
	void			*player_right_img;
	void			*floor_img;
	void			*wall_img;
	void			*exit_img;
	void			*col_img[5];
	void			*enemy_up_img;
	void			*enemy_right_img;
	void			*enemy_down_img;
	void			*enemy_left_img;
	int				height;
	int				width;
	int				col;
	int				gain;
	int				move;
	t_pos			player_pos;
	t_pos			enemy_pos;
	t_pos			col_last_pos;
	int				**cp;
	struct timeval	last_move_time;
	struct timeval	coin_move_time;
	int				coin_f;
}	t_map;

int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		validate_extension(char *av);
t_node	*create_node(char *content);
void	fill_list(t_list *list, t_node *node);
int		validate_borders(t_list *list);
int		validate_sides(char *av);
int		up_down(t_list *list);
int		map_comp(char c);
int		line_comp(char *av);
int		validate_content(t_list *list);
int		validate_map_content(t_list *list);
void	read_map(char *av, t_list *list);
int		count_elements(t_list *map, char c);
int		validate_elements(t_list *list);
int		check_form(t_list *map);
int		validate_map(t_list *list);
void	clear_list(t_list *list);
void	simple_error(t_list *list);
void	invalid_map(t_list *map);
void	ft_bzero(void *s, int n);
void	parse(char *av, t_list *list);
char	**lst_to_arr(t_list *list);
void	get_img(t_map *map);
void	draw_img(t_map *map);
int		get_height(t_map *map);
int		h_events(int keycode, t_map *map);
char	**ft_freearr(char **arr);
void	get_window(t_map *map, t_list *list);
void	move_up(t_map *map);
void	move_left(t_map *map);
void	move_down(t_map *map);
void	move_right(t_map *map);
int		validate_size(t_list *list);
int		close_window(t_map *map);
void	put_str(char *s, int fd);
void	invalid_img_file(t_map *map, void *param, char *s);
void	get_positions(t_list *list, t_pos *pos, t_pos *size, char c);
void	fill(char **map, t_pos size, t_pos current);
void	flood_fill(char **map, t_pos size, t_pos begin);
int		validate_path(t_list *list);
void	lst_to_arr_helper(t_list *list, char **arr, t_node *tmp);
void	put_player_img_up(t_map *map);
void	put_player_img_left(t_map *map);
void	put_player_img_down(t_map *map);
void	put_player_img_right(t_map *map);
void	put_img(t_map *map, int i, int j);
void	put_enemy_img_up(t_map *map);
void	put_enemy_img_left(t_map *map);
void	put_enemy_img_down(t_map *map);
void	put_enemy_img_right(t_map *map);
void	move_enemy_up(t_map *map);
void	move_enemy_left(t_map *map);
void	move_enemy_down(t_map *map);
void	move_enemy_right(t_map *map);
void	enemy_direction(t_map *map);
int		enemy_move_algo(t_map *map);
void	enemy_direction_helper2(t_map *map, int x, int y);
void	enemy_direction_helper1(t_map *map, int x, int y);
int		move_coin(t_map *map);
void	get_coin_position(t_map *map);
void	put_coin_frames(t_map *map);
void	destroy_image(t_map *map);
int		ft_ilen(int n);
char	*ft_itoa(int n);
void	display_moves(t_map *map);
void	read_error(t_list *list);
void	get_col_img(t_map *map);
void	get_enemy_img(t_map *map);
void	get_player_image(t_map *map);
void	put_img_helper(t_map *map, int i, int j);
void	win_msg(t_map *map);
void	coin_frame1(t_map *map, int i, int j);
void	coin_frame2(t_map *map, int i, int j);
void	coin_frame3(t_map *map, int i, int j);
void	coin_frame4(t_map *map, int i, int j);
void	coin_frame0(t_map *map, int i, int j);
void	put_frames(t_map *map, int i, int j);
void	destroy_img_helper(t_map *map);

#endif