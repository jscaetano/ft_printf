/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:24:50 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 18:24:50 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_printhexa(long long x, char c)
{
	char	*hex;
	int		i;
	char	*base;

	base = malloc(16 + 1);
	hex = malloc(ft_unintlen(x, c) + 1);
	i = 0;
	if (c == 'x' || c == 'p')
		ft_strcpy(base, "0123456789abcdef");
	if (c == 'X')
		ft_strcpy(base, "0123456789ABCDEF");
	while (x >= 16)
	{
		hex[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	hex[i] = base[x];
	while (i >= 0)
	{
		write(1, &hex[i], 1);
		i--;
	}
	free(hex);
	free(base);
}

void	ft_printuhexa(unsigned long long x, char c)
{
	char	*hex;
	int		i;
	char	*base;

	base = malloc(16 + 1);
	hex = malloc(ft_unintlen(x, c) + 1);
	i = 0;
	if (c == 'x' || c == 'p')
		ft_strcpy(base, "0123456789abcdef");
	if (c == 'X')
		ft_strcpy(base, "0123456789ABCDEF");
	while (x >= 16)
	{
		hex[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	hex[i] = base[x];
	while (i >= 0)
	{
		write(1, &hex[i], 1);
		i--;
	}
	free(hex);
	free(base);
}

char	*allnb(long b, char *alln)
{
	int		a;
	int		mod;

	a = 9;
	if (b != 0)
	{
		if (b < 0)
		{
			write(1, "-", 1);
			b = -1 * b;
		}
		while (b > 0)
		{
			mod = (b % 10) + 48;
			alln[a] = mod;
			a--;
			b = b / 10;
		}
	}
	else
		alln[a] = 48;
	return (alln);
}

void	ft_putnbr(long long nb)
{
	char	alln[10];
	int		i;
	int		a;

	a = 9;
	i = 0;
	while (a >= 0)
	{
		alln[a] = '\0';
		a--;
	}
	allnb(nb, alln);
	while (i < 10)
	{
		if (alln[i] != '\0')
			write(1, &alln[i], 1);
		i++;
	}
}
