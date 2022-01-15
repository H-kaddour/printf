/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:24:02 by hkaddour          #+#    #+#             */
/*   Updated: 2022/01/15 17:37:56 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		i += write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1,&s[i], 1);
		i++;
	}
	return (i);
}

int	ft_lhex(unsigned long d)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (d < 16)
		i += write(1, hex + d, 1);
	else if (d >= 16)
	{
		i += ft_lhex(d / 16);
		i += ft_lhex(d % 16);
	}
	return (i);
}

int	ft_uhex(unsigned long d)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (d < 16)
		i += write(1, hex + d, 1);
	else if (d >= 16)
	{
		i += ft_uhex(d / 16);
		i += ft_uhex(d % 16);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		if (n == -2147483648)
		{
			i += ft_putchar('2');
			n %= 1000000000;
		}
		i += ft_putnbr(-n);
	}
	else if (n >= 0 && n < 10)
	{
		i += ft_putchar(n + '0');
	}
	else
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}

int ft_unsigned(size_t n)
{
	size_t i;

	i = 0;
	if (n >= 0 && n < 10)
		i += ft_putchar(n + '0');
	else
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}
