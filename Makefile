CFILES = main.c parse/MAP/validate_extension.c parse/parse_libft.c parse/parse.c parse/MAP/validate_borders.c\
parse/MAP/validate_map_elements.c parse/MAP/validate_map.c parse/MAP/map_errors.c parse/get_next_line/get_next_line_utils.c\
parse/get_next_line/get_next_line.c \

OBJ = $(CFILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

%.o: %.c inc/so_long.h parse/get_next_line/get_next_line.h
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
