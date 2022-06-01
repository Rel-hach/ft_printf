/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:17:13 by rel-hach          #+#    #+#             */
/*   Updated: 2021/12/29 02:31:57 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *fmt, ...);
void	ft_putchar(int c, int *i);
void	ft_putstr(const char *s, int *i);
void	ft_putnbr(int n, int *i);
void	ft_puthex(unsigned int nb, char ch, int *p);
void	ft_print_adress(unsigned long int nb, int *p);
void	ft_putnbr_u(unsigned int n, int *i);
void	ft_check_flag(const char *str, int *index, int *i, va_list out);
void	ft_is_sharp(const char *str, int *index, int *i, va_list out);
void	ft_is_plus(const char *str, int *index, int *i, va_list out);
void	ft_is_space(const char *str, int *index, int *i, va_list out);

#endif
