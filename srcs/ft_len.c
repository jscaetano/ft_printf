/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:24:32 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 18:24:32 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	lenres(long long num, int div, int i, char c)
{
	if (c == 'd' || c == 'x' || c == 'X' || c == 'u'
		|| c == 'i' || c == 'u' || c == 'p')
	{
		while (num)
		{
			num /= div;
			i++;
		}
		return (i);
	}
	return (0);
}

int	unlenres(unsigned long long num, int div, int i, char c)
{
	if (c == 'd' || c == 'x' || c == 'X' || c == 'u'
		|| c == 'i' || c == 'u' || c == 'p')
	{
		while (num)
		{
			num /= div;
			i++;
		}
		return (i);
	}
	return (0);
}

int	ft_intlen(int nb, char c)
{
	int			i;
	long long	num;
	int			div;

	i = 0;
	num = nb;
	if (num == -2147483648)
		return (11);
	if (c == 'd' || c == 'i' || c == 'u')
		div = 10;
	if (c == 'x' || c == 'X' || c == 'p')
		div = 16;
	if (!num)
		return (1);
	if (num < 0)
	{
		i = 1;
		num = -num;
	}
	i = lenres(num, div, i, c);
	return (i);
}

int	ft_unintlen(unsigned long long nb, char c)
{
	int					i;
	unsigned long long	num;
	int					div;

	i = 0;
	num = nb;
	if (c == 'd' || c == 'i' || c == 'u')
		div = 10;
	if (c == 'x' || c == 'X' || c == 'p')
		div = 16;
	if (!num)
		return (1);
	i = unlenres(num, div, i, c);
	return (i);
}

int	strinlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
