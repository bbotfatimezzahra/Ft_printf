#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	main()
{
printf("%.3d",60);
}
