/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:31:35 by yohwang           #+#    #+#             */
/*   Updated: 2022/02/13 18:56:23 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(int i, va_list ap, const char *s)
{
//	%d
	if (s[i] == 'd')
	{
		int int_tmp = va_arg(ap, int);
		ft_putnbr_fd(int_tmp, 1);
		return(count_len(int_tmp) + 1);
	}
//	%c
/*
	else if (s[i] == 'c')
	{
		ft_putchar(va_arg(ap,int),1);
		return (1);
	}
*/
//	%%
	else if (s[i] == '%')
	{
		ft_putchar('%', 1);
		return (1);
	}
//	%s
//	%p
//	%i
//	%u
//	%x
//	%X
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		flag;
	int		len;
	int		i;

	i = 0;
	flag = -1;
	len = ft_strlen(s); // %만날때마다 -2, 길이만큼 +
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			flag = check_format(++i, ap, s);
			len = len - 2 + flag;
			if (!flag)
				--i;
		}
		else
			ft_putchar(s[i],1);
		i++;
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
 	ft_printf("ft: %%%b\n");
	printf("pf: %%%b\n");

/*	return value of "%" ==> 0
	int a = printf("%");
	printf("%d",a);
*/
}
