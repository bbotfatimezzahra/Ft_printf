/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:06:39 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/06 12:02:50 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

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

static int	convert_nbr(unsigned long nb, int length, char *base)
{
	int				printed;

	printed = 0;
	if (nb < (unsigned long)length)
	{
		write(1, &base[nb], 1);
		return (++printed);
	}
	else
	{
		printed += convert_nbr(nb / length, length, base);
		printed += convert_nbr(nb % length, length, base);
	}
	return (printed);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	length;

	length = check_base(base);
	if (length > 1)
		return (convert_nbr(nbr, length, base));
	return (0);
}
