/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writearg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:43:18 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/03 12:23:48 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		*ft_writearg(char specifier)
{
	char	*decimal;
	char	*lowerhexa;
	char	*upperhexa;

	decimal = "0123456789";
	lowerhexa = "0123456789abcdef";
	upperhexa = "0123456789ABCDEF";
	if (specifier == '%')
		return (ft_putchar('%'));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(arglist, int)));
	else if (specifier == 'u')
		return (ft_putunbr(va_arg(arglist, unsigned int)));
	else if (specifier == 'x')
		return (ft_putnbr_base(va_arg(arglist, unsigned int), decimal, lowerhexa));
	else if (specifier == 'X')
		return (ft_putnbr_base(va_arg(arglist, unsigned int), decimal, upperhexa));
	else if (specifier == 'c')
		return (ft_putchar(va_arg(arglist, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(arglist, char *)));
	else if (specifier == 'p')
		return (ft_putpointer(va_arg(arglist, void *)));
	else
		return (0);
}
