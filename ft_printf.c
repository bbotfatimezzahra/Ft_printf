/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:49:08 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/03 11:53:08 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	int		printed;
	va_list	arglist;

	va_start(arglist, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i++], 1);
		else
		{
			if (ft_strchr(SPECIFIERS, format[++i]))
				i += ft_writearg(&format[i + 1]);
			else if (ft_strchr(FLAGS, format[i]))
				i += ft_writeflag(format[i]);
		}
	}
	va_end(arglist);
	return (i);
}
