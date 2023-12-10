/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:45:22 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/06 12:03:03 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *p)
{
	unsigned long	address;

	address = (unsigned long)p;
	write(1, "0x", 2);
	return (ft_putnbr_base(address, "0123456789abcdef") + 2);
}
