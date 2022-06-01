/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 05:52:28 by rel-hach          #+#    #+#             */
/*   Updated: 2021/12/29 01:34:36 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(const char *str, int *index, int *i, va_list out)
{
	if (str[*index] == ' ')
		ft_is_space (str, index, i, out);
	if (str[*index] == '+')
		ft_is_plus (str, index, i, out);
	if (str[*index] == '#')
		ft_is_sharp (str, index, i, out);
}

void	ft_is_sharp(const char *str, int *index, int *i, va_list out)
{
	int	num;

	num = va_arg(out, int);
	while (str[*index] == '#')
		(*index)++;
	if (str[*index] == 'x')
	{
		if (num == 0)
			ft_putstr("0", i);
		else
		{
			ft_putstr("0x", i);
			ft_puthex(num, str[*index], i);
		}
	}
	if (str[*index] == 'X')
	{
		if (num == 0)
			ft_putstr("0", i);
		else
		{
			ft_putstr("0X", i);
			ft_puthex(num, str[*index], i);
		}
	}
}

void	ft_is_plus(const char *str, int *index, int *i, va_list out)
{
	int	num;

	while (str[*index] == '+')
		(*index)++;
	if (str[*index] == 'd' || str[*index] == 'i')
	{
		num = va_arg(out, int);
		if (num < 0)
			ft_putnbr(num, i);
		else
		{
			ft_putchar('+', i);
			ft_putnbr(num, i);
		}
	}
}

void	ft_is_space(const char *str, int *index, int *i, va_list out)
{
	int	num;

	num = va_arg(out, int);
	while (str[*index] == ' ')
		(*index)++;
	if ((str[*index] == 'd' || str[*index] == 'i') && num >= 0)
		ft_putchar(' ', i);
	ft_putnbr(num, i);
}
