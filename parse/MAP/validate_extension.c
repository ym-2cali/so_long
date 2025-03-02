#include "../../inc/so_long.h"

int validate_extension(char *av)
{
    int len;

    len = ft_strlen(av) - 4;
    if (len > 0 && av[len] == '.' && av[len + 1] == 'b' && av[len + 2] == 'e' && av[len + 3] == 'r')
        return (1);
    return (0);
}
