/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:24:40 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 18:24:40 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*strinchr(const char *str)
{
	while (*str)
	{
		if (*str == '%')
			return ((char *)str);
		str++;
	}
	if (!str)
		return ((char *)str);
	return (0);
}

const char	*ft_read(t_print *st, const char *format)
{
	char	*next;

	next = strinchr(format);
	if (next)
		st->wdt = next - format;
	else
		st->wdt = strinlen(format);
	write(1, format, st->wdt);
	st->len += st->wdt;
	while (*format && *format != '%')
		++format;
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_print		st;

	va_start(args, format);
	st.len = 0;
	st.wdt = 0;
	while (*format)
	{
		if (*format == '%' && *format - 1 != '%')
			format = ft_var(args, format + 1, &st);
		else
			format = ft_read(&st, format);
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(args);
			return (st.len);
		}
	}
	va_end(args);
	return (st.len);
}

// #include <stdio.h>

// int main(void)
// {
// 	write(1, "ft_printf:\n", 12);

// 	int	res = ft_printf("%p\n", (void *)0xdeadc0de, 0,
// (int)-2147483648, -1, -1, 200000000);

// 	write(1, "\nprintf:\n", 9);

// 	int	res2 = printf("%p\n", (void *)0xdeadc0de);

// 	printf("\nft_printf = %d\nprintf = %d\n", res, res2);

// 	return 0;
// }
