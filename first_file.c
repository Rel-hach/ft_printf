/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:17:39 by rel-hach          #+#    #+#             */
/*   Updated: 2021/12/29 02:31:25 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

void	ft_putstr(const char *s, int *i)
{
	int	j;

	j = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*i += 6;
	}
	else if (s[j] != '\0')
	{
		while (s[j] != '\0')
		{
			ft_putchar(s[j], i);
			j++;
		}
	}
}

void	ft_putnbr(int n, int *i)
{
	if (n < 0)
	{
		ft_putchar('-', i);
		if (n == -2147483648)
		{
			ft_putstr("2147483648", i);
		}
		n = n * (-1);
	}
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + 48, i);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, i);
		ft_putnbr(n % 10, i);
	}
}

void	ft_putnbr_u(unsigned int n, int *i)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + 48, i);
	}
	if (n >= 10)
	{
		ft_putnbr_u(n / 10, i);
		ft_putnbr_u(n % 10, i);
	}
}
