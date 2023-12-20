/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzero_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:53:36 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/20 08:53:39 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexaflag(va_list arglist, int *index, char flag)
{
	unsigned int	arg;

	arg = va_arg(arglist, unsigned int);
	++(*index);
	if (arg != 0)
	{
		write(1, "0", 1);
		write(1, &flag, 1);
		if (flag == 'x')
			return (ft_putnbr_base(arg, HEXALOWER) + 2);
		else
			return (ft_putnbr_base(arg, HEXAUPPER) + 2);
	}
	return (ft_putnbr_base(arg, HEXAUPPER));
}

int	ft_putzero(const char *format, va_list arglist, int *index)
{
	int	flip;

	(*index)++;
	flip = 0;
	while (ft_strchr(FLAGS, format[*index]))
	{
		if ((format[*index] == '+' || format[*index] == ' ') && !flip)
			flip = *index;
		(*index)++;
	}
	if (ft_strchr(SPECIFIERS, format[*index]))
	{
		if (format[*index] == 'x' || format[*index] == 'X')
			return (ft_hexaflag(arglist, index, format[*index]));
		else
		{
			if (flip)
			{
				*index = flip;
				return (ft_writeflag(format, arglist, index));
			}
		}
		return (ft_writearg(format[*index], arglist, index));
	}
	return (0);
}
