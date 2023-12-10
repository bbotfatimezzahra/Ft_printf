/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:22:32 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/06 17:36:25 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writeflag(const char *format, va_list arglist, int *index)
{
	if (format[*index] == '+')
		return (ft_putsign(format, arglist, index, 0));
	else if (format[*index] == ' ')
		return (ft_putblank(format, arglist, index, 0));
	else if (format[*index] == '#')
		return (ft_putzero(format, arglist, index));
	return (0);
}
