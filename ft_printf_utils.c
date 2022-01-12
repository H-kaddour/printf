/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:24:02 by hkaddour          #+#    #+#             */
/*   Updated: 2022/01/12 17:55:34 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char s)
{
	int	i;

	i = 0;
	i++;
	write(1, &s, 1);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1,&s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n %= 1000000000;
		}
		ft_putnbr(-n);
	}
	else if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0');
	}
	else
	{
		i += ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (i);
}

