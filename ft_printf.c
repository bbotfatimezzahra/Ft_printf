/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:54:02 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/16 15:54:15 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			else if (ft_strchr(FLAGS, format[++i]))
				printed += ft_writeflag(format, arglist, &i);
		}
	}
	va_end(arglist);
	return (printed);
}
