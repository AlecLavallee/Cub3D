#include "libft.h"

void	ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
}
