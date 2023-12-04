/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:31:22 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/03 16:21:38 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int nb)
{
	unsigned int	unb;
	char			c;
	int				length;

	length = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		length++;
		unb = -nb;
	}
	else
		unb = nb;
	if (unb < 10)
	{
		c = unb + '0';
		write(1, &c, 1);
		return (++length);
	}
	else
	{
		length += ft_putnbr(unb / 10);
		length +=ft_putnbr(unb % 10);
	}
	return (length);
}

int	ft_putunbr(unsigned int unb)
{
	char			c;
	int				length;

	length = 0;
	if (unb < 10)
	{
		c = unb + '0';
		write(1, &c, 1);
		return (++length);
	}
	else
	{
		length += ft_putunbr(unb / 10);
		length +=ft_putunbr(unb % 10);
	}
	return (length);
}
