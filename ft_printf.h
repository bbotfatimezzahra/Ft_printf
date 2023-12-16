/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:49 by fbbot             #+#    #+#             */
/*   Updated: 2023/12/16 15:53:33 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "# +"
# define HEXALOWER "0123456789abcdef"
# define HEXAUPPER "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
int		ft_writearg(char specifier, va_list arglist, int *index);
int		ft_strlen(const char *str);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int unb);
int		ft_putnbr_base(unsigned long nbr, char *base);
int		ft_putpointer(void *p);
int		ft_writeflag(const char *format, va_list arglist, int *index);
int		ft_putsign(const char *format, va_list arglist, int *index, int flip);
int		ft_putblank(const char *format, va_list arglist, int *index, int flip);
int		ft_putzero(const char *format, va_list arglist, int *index);

#endif
