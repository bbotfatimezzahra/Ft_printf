/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writearg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:43:18 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/05 14:59:23 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_writearg(char specifier, va_list arglist, int *index)
{
	(*index)++;
	if (specifier == '%')
		return (ft_putchar('%'));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(arglist, int)));
	else if (specifier == 'u')
		return (ft_putunbr(va_arg(arglist, unsigned int)));
	else if (specifier == 'x')
		return (ft_putnbr_base(va_arg(arglist, unsigned int), HEXALOWER));
	else if (specifier == 'X')
		return (ft_putnbr_base(va_arg(arglist, unsigned int), HEXAUPPER));
	else if (specifier == 'c')
		return (ft_putchar(va_arg(arglist, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(arglist, char *)));
	else if (specifier == 'p')
		return (ft_putpointer(va_arg(arglist, void *)));
	else
		return (0);
}
