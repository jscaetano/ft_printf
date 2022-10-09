/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:25:07 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 18:25:07 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_print
{
	int	wdt;
	int	len;
}	t_print;

char 		*ft_strcpy(char *dest, char *src);
int			strinlen(const char *s);
char		*strinchr(const char *str);
const char	*ft_read(t_print *st, const char *format);
int			ft_printf(const char *format, ...);
int			lenres(long long num, int div, int i, char c);
int			unlenres(unsigned long long num, int div, int i, char c);
int			ft_intlen(int nb, char c);
int			ft_unintlen(unsigned long long nb, char c);
void		ft_putstr(const char *str);
void		ft_printhexa(long long x, char c);
void		ft_printuhexa(unsigned long long x, char c);
char		*allnb(long b, char *alln);
void		ft_putnbr(long long nb);
void		ft_vardiu(va_list args, const char *format, t_print *st);
void		ft_varsxx(va_list args, const char *format, t_print *st);
void		ft_varcpp(va_list args, const char *format, t_print *st);
void		ft_varp(va_list args, const char *format, t_print *st);
const char	*ft_var(va_list args, const char *format, t_print *st);

#endif
