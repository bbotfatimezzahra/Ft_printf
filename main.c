#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int	unb;
	char			c;

	if (nb < 0)
	{
		write(1, "-", 1);
		unb = -nb;
	}
	else
		unb = nb;
	if (unb < 10)
	{
		c = unb + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(unb / 10);
		ft_putnbr(unb % 10);
	}
}
int	main()
{
printf("%d\n","hi");
ft_putnbr("hi");
}
