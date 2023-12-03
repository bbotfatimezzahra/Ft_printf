/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:06:39 by fbbot             #+#    #+#             */
/*   Updated: 2023/11/28 12:18:24 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static void	convert_putint(long nb, int length, char *base)
{
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	if (nb < (long)length)
		write(1, &base[nb], 1);
	else
	{
		convert_putint(nb / length, length, base);
		convert_putint(nb % length, length, base);
	}
}

void	ft_putint_base(long nbr, char *base)
{
	int	length;

	length = check_base(base);
	if (length > 1)
		convert_putint(nbr, length, base);
}
