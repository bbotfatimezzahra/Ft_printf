/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:22:54 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/06 12:03:24 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intflag(va_list arglist, int *index, char flag)
{
	int	arg;

	arg = va_arg(arglist, int);
	++(*index);
	if (arg >= 0)
	{
		write(1, &flag, 1);
		return (ft_putnbr(arg) + 1);
	}
	return (ft_putnbr(arg));
}

int	ft_putsign(const char *format, va_list arglist, int *index, int flip)
{
	(*index)++;
	while (ft_strchr(FLAGS, format[*index]))
	{
		if (format[*index] == '#')
			flip = *index;
		(*index)++;
	}
	if (ft_strchr(SPECIFIERS, format[*index]))
	{
		if (format[*index] == 'i' || format[*index] == 'd')
			return (ft_intflag(arglist, index, '+'));
		else
		{
			if (flip)
			{
				*index = flip;
				return (ft_putzero(format, arglist, index));
			}
		}
		return (ft_writearg(format[*index], arglist, index));
	}
	return (0);
}

int	ft_putblank(const char *format, va_list arglist, int *index, int flip)
{
	(*index)++;
	while (ft_strchr(FLAGS, format[*index]))
	{
		if (format[*index] == '+')
			return (ft_putsign(format, arglist, index, flip));
		else if (format[*index] == '#')
			flip = *index;
		(*index)++;
	}
	if (ft_strchr(SPECIFIERS, format[*index]))
	{
		if (format[*index] == 'i' || format[*index] == 'd')
			return (ft_intflag(arglist, index, ' '));
		else
		{
			if (flip)
			{
				*index = flip;
				return (ft_putzero(format, arglist, index));
			}
		}
		return (ft_writearg(format[*index], arglist, index));
	}
	return (0);
}
