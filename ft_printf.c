/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:14:45 by hkaddour          #+#    #+#             */
/*   Updated: 2022/01/14 19:16:43 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_params(char str, int i, va_list args)
{
	if (str == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (str == 'd' || str == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (str == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (str == 'x')
		i += ft_lhex(va_arg(args, unsigned int));
	else if (str == 'X')
		i += ft_uhex(va_arg(args, unsigned int));
	else if (str == 'u')
		i += ft_unsigned(va_arg(args, unsigned int));
	else if (str == 'p')
		i += ft_pointer(va_arg(args, unsigned long int));
	else if (str == '%')
		i += ft_putchar(str);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int	i;

	i = 0;
	va_list args;
	va_start(args, str);

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i = ft_params(*str, i,args);
		}
		else
		{
			i += write(1, str, 1);
		}
		str++;
		va_end(args);
	}
	return (i);
}

int main()
{
	//char *arr="kaddouri";
	int n = ft_printf("%x %X", -1, -1);
	printf("\n%d", n);
}




        //str:                             //args
//("hicham %% %c %s %p %d %i %u %x %X", c, s, p, d, i, u, x, X);
