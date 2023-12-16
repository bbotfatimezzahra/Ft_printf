/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:06:39 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/13 22:04:39 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_base(unsigned long nb, char *base)
{
	int				printed;

	printed = 0;
	if (nb < 16)
	{
		write(1, &base[nb], 1);
		return (++printed);
	}
	else
	{
		printed += ft_putnbr_base(nb / 16, base);
		printed += ft_putnbr_base(nb % 16, base);
	}
	return (printed);
}
