/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:31:35 by yohwang           #+#    #+#             */
/*   Updated: 2022/02/12 17:22:31 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char c, va_list ap, const char *s)
{
	int	count;
	int	tmp;
//	%d
//	int int_tmp = va_arg(ap, int);
//	char tmp = int_tmp + '0';
//	write(1, &tmp, 1);
//	%c
//	ft_putchar(va_arg(ap,int),1);
//	%%%%%%
	count = 1;
	while (s[count] == '%')
		count++;
	tmp = count;
	while (tmp - 2 >= 0)
	{
		ft_putchar('%', 1);
		tmp = tmp - 2;
	}
	return (count);
//	%s
//	%p
//	%i
//	%u
//	%x
//	%X
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		flag;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s); // %만날때마다 -2, 길이만큼 +
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			i = i + check_format(i, ap, s);
		else
			write(1, &s[i++], 1);
	}
	return (len);
}

#include <stdio.h>

int main()
{
	char c = '7';
	printf("%%%%\n");
	ft_printf("%%%%\n");
	//printf("%%");
}
