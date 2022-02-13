/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:31:35 by yohwang           #+#    #+#             */
/*   Updated: 2022/02/13 18:06:32 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(int i, va_list ap, const char *s)
{
	int	count;
	int	tmp;
//	%d
/*
	int int_tmp = va_arg(ap, int);
	ft_putnbr_fd(int_tmp, 1);
	return(count_len(int_tmp) + 1);
*/
//	%c
/*
	ft_putchar(va_arg(ap,int),1);
	return (1);
*/
//	%%
/*
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
*/
//	%s
//	%p
//	%i
//	%u
//	%x
//	%X
	return (0);
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
		if (s[i++] == '%')
			len = len - 2 + check_format(i++, ap, s);
		else
			write(1, &s[i++], 1);
	}
	return (len);
}

#include <stdio.h>

int main()
{
/*	%d
	int	a = 2147483647;
	int b = printf("printf: %d\n", a);
	int c = ft_printf("printf: %d\n",a);
	printf("%d, %d \n",b,c);
*/
//	%%
// 	printf("%%%\n");

/*	return value of "%" ==> 0
	int a = printf("%");
	printf("%d",a);
*/
}
