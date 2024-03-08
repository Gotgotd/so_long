/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:37:59 by gdaignea          #+#    #+#             */
/*   Updated: 2023/10/24 14:45:33 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(char *str);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbr_base(unsigned long int n, char *base, int *count);
void	ft_putnbr_pointer(unsigned long int n, int *count);
int		ft_printf(const char *s, ...);
void	check_format(va_list args, char c, int *count);

#endif