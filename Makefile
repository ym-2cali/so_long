CFILES = main.c parse/MAP/validate_extension.c parse/parse_libft.c parse/parse.c parse/MAP/validate_borders.c\
parse/MAP/validate_map_elements.c parse/MAP/validate_map.c parse/MAP/map_errors.c parse/get_next_line/get_next_line_utils.c\
parse/get_next_line/get_next_line.c window.c window_utils.c libft_utils.c game_utils.c moves.c errors.c \

OBJ = $(CFILES:.c=.o)

CC = cc

CFLAGS = -g -Wall -Wextra -Werror 
NAME = so_long

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ)  -o $(NAME) 

%.o: %.c inc/so_long.h parse/get_next_line/get_next_line.h
	$(CC) $(CFLAGS) -Imlx  -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
