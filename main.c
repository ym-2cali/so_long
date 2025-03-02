#include "inc/so_long.h"

int	main(int ac, char **av)
{
    (void)ac;
	printf("%d\n", validate_extension(av[1]));
}
