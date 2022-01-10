/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:14:45 by hkaddour          #+#    #+#             */
/*   Updated: 2022/01/10 19:03:31 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *) str;
	va_list args;
	va_start(args, str);

	while (s[i])
	{
		if (s[i++] == '%')
		{
			if (s[i++] == 'd')
				j += ft_putstr(va_arg(args, char *));
		}
	}
	return (j);
}

int main()
{
	char arr[]="hicham";
	int n = ft_printf("%d", arr);
	printf("%d", n);
}
