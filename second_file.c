/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:17:50 by rel-hach          #+#    #+#             */
/*   Updated: 2021/12/28 00:30:02 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int nb, char ch, int *p)
{
	char	hex[10];
	char	*str;
	int		temp;
	int		i;

	i = 0;
	if (nb == 0)
		ft_putnbr(nb, p);
	while (nb != 0)
	{
		if (ch == 'x')
			str = "0123456789abcdef";
		else if (ch == 'X')
			str = "0123456789ABCDEF";
		temp = nb % 16;
		hex[i++] = str[temp];
		nb = nb / 16;
	}
	hex[i] = '\0';
	while (--i >= 0)
		ft_putchar(hex[i], p);
}

void	ft_print_adress(unsigned long int nb, int *p)
{
	char	hex[16];
	char	*str;
	int		temp;
	int		i;

	i = 0;
	str = "0123456789abcdef";
	ft_putchar('0', p);
	ft_putchar('x', p);
	if (nb == 0)
		ft_putnbr(nb, p);
	while (nb != 0)
	{
		temp = nb % 16;
		hex[i++] = str[temp];
		nb = nb / 16;
	}
	hex[i] = '\0';
	while (--i >= 0)
		ft_putchar(hex[i], p);
}
