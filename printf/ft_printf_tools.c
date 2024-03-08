/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:41:51 by gdaignea          #+#    #+#             */
/*   Updated: 2023/10/24 15:47:25 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		*count += write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	long int	nb;
	char		res;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		*count += write(1, "-", 1);
	}
	if (nb > 9)
		ft_putnbr((nb / 10), count);
	res = nb % 10 + '0';
	*count += write(1, &res, 1);
}

void	ft_putnbr_base(unsigned long int n, char *base, int *count)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n / base_len > 0)
		ft_putnbr_base(n / base_len, base, count);
	*count += write(1, (&base[n % base_len]), 1);
}
