/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:28:01 by gdaignea          #+#    #+#             */
/*   Updated: 2023/11/22 15:50:56 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pointer(unsigned long int n, int *count)
{
	if (!n)
	{
		*count += write(1, "(nil)", 5);
		return ;
	}
	*count += write(1, "0x", 2);
	ft_putnbr_base(n, "0123456789abcdef", count);
}

void	check_format(va_list args, char c, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	if (c == 'p')
		ft_putnbr_pointer(va_arg(args, unsigned long int), count);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), count);
	if (c == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", count);
	if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", count);
	if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			check_format(args, s[i], &count);
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("ma fonction : %c\n", '0');
	printf("la vraie fonction : %c\n", '0');
	ft_printf("ma fonction : %s\n", "bonjour");
	printf("la vraie fonction : %s\n", "bonjour");
	ft_printf("ma fonction : %d\n", 123456);
	printf("la vraie fonction : %d\n", 123456);
	ft_printf("ma fonction : %i\n", 123456);
	printf("la vraie fonction : %i\n", 123456);
	ft_printf("ma fonction : %u\n", -123456);
	printf("la vraie fonction : %u\n", -123456);
	ft_printf("ma fonction : %x\n", 123456);
	printf("la vraie fonction : %x\n", 123456);
	ft_printf("ma fonction : %X\n", 123456);
	printf("la vraie fonction : %X\n", 123456);
	ft_printf("ma fonction : %%\n");
	printf("la vraie fonction : %%\n");
	ft_printf("ma fonction : %p\n", "bonjour");
	printf("la vraie fonction : %p\n", "bonjour");
	return (0);
}