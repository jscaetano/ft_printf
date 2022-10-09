/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:24:57 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 18:24:57 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_vardiu(va_list args, const char *format, t_print *st)
{
	int				d;
	unsigned int	u;

	if (*format == 'd' || *format == 'i')
	{
		d = va_arg(args, int);
		ft_putnbr((long)d);
		st->len += ft_intlen((long)d, *format);
	}
	else if (*format == 'u')
	{
		u = va_arg(args, unsigned int);
		ft_putnbr((long)u);
		st->len += ft_unintlen((long)u, *format);
	}
}

void	ft_varsxx(va_list args, const char *format, t_print *st)
{
	char			*s;
	unsigned int	x;

	if (*format == 's')
	{
		s = va_arg(args, char *);
		if (!s)
		{
			write(1, "(null)", 6);
			st->len += 6;
		}
		else
		{
			ft_putstr(s);
			st->len += strinlen(s);
		}
	}
	else if (*format == 'x' || *format == 'X')
	{
		x = va_arg(args, unsigned int);
		ft_printuhexa((unsigned long)x, *format);
		st->len += ft_unintlen((unsigned long long)x, *format);
	}
}

void	ft_varcp(va_list args, const char *format, t_print *st)
{
	char				c;

	if (*format == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		st->len += 1;
	}
	else if (*format == '%')
	{
		write(1, "%", 1);
		st->len += 1;
	}
}

void	ft_varp(va_list args, const char *f, t_print *st)
{
	long long			p;
	unsigned long long	r;

	r = 18446744073709551615u;
	if (*f == 'p')
	{
		p = va_arg(args, long long);
		if (p)
		{
			write (1, "0x", 2);
			r = r + p + 1;
			ft_printuhexa(r, *f);
			st->len += ft_unintlen((unsigned long long)r, *f) + 2;
		}
		else
		{
			write(1, "(nil)", 5);
			st->len += 5;
		}
	}
}

const char	*ft_var(va_list args, const char *format, t_print *st)
{
	if (*format == 'd' || *format == 'i')
		ft_vardiu(args, format, st);
	else if (*format == 'u')
		ft_vardiu(args, format, st);
	else if (*format == 's')
		ft_varsxx(args, format, st);
	else if (*format == 'x' || *format == 'X')
		ft_varsxx(args, format, st);
	else if (*format == 'c')
		ft_varcp(args, format, st);
	else if (*format == 'p')
		ft_varp(args, format, st);
	else if (*format == '%')
		ft_varcp(args, format, st);
	else
		return (0);
	format++;
	return (format);
}

// if (p > 0)
// 			{
// 				ft_printhexa(p, *f);
// 				st->len += ft_unintlen((unsigned long long)p, *f) + 2;
// 			}
// 			else
// 			{
// 				r = r + p + 1;
// 				ft_printuhexa(r, *f);
// 				st->len += ft_unintlen((unsigned long long)r, *f) + 2;
// 			}
