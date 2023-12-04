/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:22:32 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/04 18:08:43 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putsign(const char *format, va_list arglist, int *index)
{
	int	i;
	int arg;

	i = 1;
	while (ft_strchr(FLAGS, format[i++]))
		index++;
	if (format[i] == 'i' || format[i] == 'd')
	{
		arg = va_arg(arglist, int);
		if(arg >= 0)
			write(1, "+", 1);
		else
			write(1, "-", 1);
		return (ft_putnbr(arg) + 1);
	}
	return (0);
}

int	ft_writeflag(const char *format, va_list arglist, int *index)
{

	if (*format == '+')
		return (ft_putsign(format, arglist, index));
return (0);			
}
