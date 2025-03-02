CFILES = main.c parse/MAP/validate_extension.c parse/parse_libft.c pare/parse.c parse/MAP/validate_borders.c\

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
