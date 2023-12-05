/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:49:08 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/05 15:00:17 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	length;

	length = ft_strlen(s);
	i = 0;
	while (i <= length)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed;
	va_list	arglist;

	va_start(arglist, format);
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i++], 1);
			printed++;
		}
		else
		{
			if (ft_strchr(SPECIFIERS, format[i + 1]))
				printed += ft_writearg(format[++i], arglist, &i);
			else if (ft_strchr(FLAGS, format[i + 1]))
				printed += ft_writeflag(&format[++i], arglist, &i);
		}
	}
	va_end(arglist);
	return (printed);
}
