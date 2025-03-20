CFILES = $(addprefix mandatory/src/, main.c parse/MAP/validate_extension.c parse/parse_libft.c parse/parse.c parse/MAP/validate_borders.c\
parse/MAP/validate_map_elements.c parse/MAP/validate_map.c parse/MAP/map_errors.c parse/get_next_line/get_next_line_utils.c\
parse/get_next_line/get_next_line.c graphics/window.c graphics/window_utils.c libft_utils.c graphics/moves.c graphics/moves_utils.c errors.c parse/MAP/validate_path.c)

CFILES_BONUS = $(addprefix bonus/src_bonus/, main_bonus.c parse_bonus/MAP_bonus/validate_extension_bonus.c parse_bonus/parse_libft_bonus.c parse_bonus/parse_bonus.c parse_bonus/MAP_bonus/validate_borders_bonus.c\
parse_bonus/MAP_bonus/validate_map_elements_bonus.c parse_bonus/MAP_bonus/validate_map_bonus.c parse_bonus/MAP_bonus/map_errors_bonus.c parse_bonus/get_next_line/get_next_line_utils.c\
parse_bonus/get_next_line/get_next_line.c graphics_bonus/window_bonus.c graphics_bonus/window_utils_bonus.c libft_utils_bonus.c graphics_bonus/moves_bonus.c graphics_bonus/moves_utils_bonus.c errors_bonus.c parse_bonus/MAP_bonus/validate_path_bonus.c\
enemy/enemy_moves.c enemy/enemy_moves_utils.c enemy/enemy_move_algo.c)

OBJ = $(CFILES:.c=.o)

OBJ_BONUS = $(CFILES_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -ggdb #-fsanitize=address

NAME = so_long

NAME_BONUS = so_long_bonus

all:$(NAME)

$(NAME):$(OBJ) mandatory/inc/so_long.h mandatory/src/parse/get_next_line/get_next_line.h
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ)  -o $(NAME) 

bonus:$(NAME_BONUS)

$(NAME_BONUS):$(OBJ_BONUS) bonus/inc_bonus/so_long_bonus.h bonus/src_bonus/parse_bonus/get_next_line/get_next_line.h
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ_BONUS) -o $(NAME_BONUS) 

%.o: %.c
	$(CC) $(CFLAGS) -Imlx  -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean
