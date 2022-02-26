/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:31:35 by yohwang           #+#    #+#             */
/*   Updated: 2022/02/26 14:56:24 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(int i, va_list *ap, const char *s)
{
	long long	int_tmp;

	if (s[i] == 'd')
	{
		int_tmp = va_arg(*ap, int);
		ft_putnbr_fd(int_tmp, 1);
		if (int_tmp < 0)
			return (count_len(-int_tmp) + 2);
		else
			return (count_len(int_tmp) + 1);
	}
	else if (s[i] == 'c')
		return (ft_putchar_len(va_arg(*ap, int)));
	else if (s[i] == '%')
		return (ft_putchar_len('%'));
	else if (s[i] == 's')
		return (ft_putstr_len(va_arg(*ap, char *)));
		/*
	else if (s[i] == 'p')
		return (ft_putptr_len(va_arg(ap, unsigned long long)));
//	%i
	else if (s[i] == 'i')
		return (0);
//	%u
	else if (s[i] == 'u')
		return (ft_putunsigned_len(va_arg(ap, unsigned int)));
//	%x %X
	else if (s[i] == 'x' || s[i] == 'X')
		return (ft_puthex_len(va_arg(ap, unsigned int), s[i]));*/
	else
		return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		flag;
	int		len;
	int		i;

	i = -1;
	flag = -1;
	len = ft_strlen(s); // %만날때마다 -2, 길이만큼 +
	va_start(ap, s);
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			flag = check_format(++i, &ap, s);
			if (flag == -1)
			{
				flag = 1;
				i--;
			}
			len = len - 2 + flag;
		}
		else
			ft_putchar_len(s[i]);
	}
	va_end(ap);
	return (len);
}
/*
#include <stdio.h>
int main() {
	int i =	ft_printf(" %d ", -10);
	printf("%d",i);
//	printf(" NULL %s NULL ", (char *)0);
}*/
