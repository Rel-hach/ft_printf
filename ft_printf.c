/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:38:52 by rel-hach          #+#    #+#             */
/*   Updated: 2021/12/29 02:31:46 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_fmt_specifier(char c, int *i, va_list out)
{
	if (c == 'c')
		ft_putchar(va_arg(out, int), i);
	else if (c == 's')
		ft_putstr(va_arg(out, char *), i);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(out, int), i);
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(out, unsigned int), c, i);
	else if (c == 'p')
		ft_print_adress(va_arg(out, unsigned long int), i);
	else if (c == 'u')
		ft_putnbr_u(va_arg(out, unsigned int), i);
	else if (c == '%')
		ft_putchar('%', i);
}

int	ft_isnormal(char c)
{
	return (c == 'c' || c == 's' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'p' || c == '%');
}

int	ft_isflag(char c)
{
	return (c == ' ' || c == '#' || c == '+');
}

int	ft_printf(const char *fmt, ...)
{
	va_list	out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(out, fmt);
	while (fmt[j])
	{
		if (fmt[j] == '%')
		{
			j++;
			if (ft_isnormal(fmt[j]))
				ft_check_fmt_specifier(fmt[j], &i, out);
			else if (ft_isflag(fmt[j]))
				ft_check_flag(fmt, &j, &i, out);
		}
		else
			ft_putchar(fmt[j], &i);
		j++;
	}
	va_end(out);
	return (i);
}
