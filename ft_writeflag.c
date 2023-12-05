/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:22:32 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/05 18:50:22 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_intflag(va_list arglist, int *index, char flag)
{
	int	arg;

	arg = va_arg(arglist, int);
	++(*index);
	if(arg >= 0)
	{
		write(1, &flag, 1);
		return (ft_putnbr(arg) + 1);
	}
	return (ft_putnbr(arg));
}

int	ft_putsign(const char *format, va_list arglist, int *index, int flop)
{
	int	i;
	int	flip;

	i = 1;
	(*index)++;
	if (flop)
		flip = flop;
	flip = 0;
	while (ft_strchr(FLAGS, format[i]))
	{
		if (format[i] == '#')
			flip = *index;
		i++;
		(*index)++;
	}
	if (ft_strchr(SPECIFIERS, format[i]))
	{
		if (format[i] == 'i' || format[i] == 'd')
			return (ft_intflag(arglist, index, '+'));
		else
		{
			if (flip)
			{
				i = *index - i + 1;
				*index = flip + 1;
				return (ft_putzero(&format[i], arglist, index));
			}
		}
		return (ft_writearg(format[i], arglist, index));
	}
	return (0);
}

int	ft_putblank(const char *format, va_list arglist, int *index)
{
	int	i;
	int	flip;

	i = 1;
	(*index)++;
	flip = 0;
	while (ft_strchr(FLAGS, format[i]))
	{
		if (format[i] == '+')
			return (ft_putsign(&format[i], arglist, index, flip));
		else if (format[i] == '#')
			flip = *index;
		i++;
		(*index)++;
	}
	if (ft_strchr(SPECIFIERS, format[i]))
	{
		if (format[i] == 'i' || format[i] == 'd')
			return (ft_intflag(arglist, index, ' '));
		else
		{
			if (flip)
			{
				i = *index - i + 1;
				*index = flip + 1;
				return (ft_putzero(&format[i], arglist, index));
			}
		}
		return (ft_writearg(format[i], arglist, index));
	}
	return (0);
}

static int	ft_hexaflag(va_list arglist, int *index, char flag)
{
	unsigned int	arg;

	arg = va_arg(arglist, unsigned int);
	++(*index);
	if(arg != 0)
	{
		write(1,"0", 1);
		write(1,&flag, 1);
		if (flag == 'x')
			return (ft_putnbr_base(arg, HEXALOWER) + 2);
		else
			return (ft_putnbr_base(arg, HEXAUPPER) + 2);
	}
	return (ft_putnbr_base(arg, HEXAUPPER));
}

int	ft_putzero(const char *format, va_list arglist, int *index)
{
	int	i;
	int	flip;

	i = 1;
	(*index)++;
	flip = 0;
	while (ft_strchr(FLAGS, format[i]))
	{
		if ((format[i] == '+' || format[i] == ' ') && !flip)
			flip = *index;
		i++;
		(*index)++;
	}
	if (ft_strchr(SPECIFIERS, format[i]))
	{
		if (format[i] == 'x' || format[i] == 'X')
			return (ft_hexaflag(arglist, index, format[i]));
		else
		{
			if (flip)
			{
				i = *index - i + 1;
				*index = flip;
				return (ft_writearg(format[i], arglist, index));
			}
		}
		return (ft_writearg(format[i], arglist, index));
	}
	return (0);
}
int	ft_writeflag(const char *format, va_list arglist, int *index)
{

	if (*format == '+')
		return (ft_putsign(format, arglist, index, 0));
	else if (*format == ' ')
		return (ft_putblank(format, arglist, index));
	else if (*format == '#')
		return (ft_putzero(format, arglist, index));
return (0);			
}
