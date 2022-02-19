/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:31:35 by yohwang           #+#    #+#             */
/*   Updated: 2022/02/19 17:17:41 by yohwang          ###   ########.fr       */
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
	else if (s[i] == 'c')
		return(ft_putchar_len(va_arg(ap, int));
//	%%
	else if (s[i] == '%')
		return(ft_putchar_len('%'));
//	%s
	else if (s[i] == 's')
		return (ft_putstr_len(va_arg(ap, char *)));
//	%p
	else if (s[i] == 'p')
		return (ft_putptr_len(va_arg(ap, unsigned long long)));
//	%i
	else if (s[i] == 'i)
		return (0);
//	%u
	else if (s[i] == 'u')
		return (ft_putunsigned_len(va_arg(ap, unsigned int)));
//	%x %X
	else if (s[i] == 'x' || s[i] == 'X')
		return (ft_puthex_len(va_arg(ap, unsigned int), s[i]));
	else
		return (0);
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
			flag = check_format(++i, ap, s);
			if (!flag)
			{
				flag++;
				i--;
			}
			len = len - 2 + flag;
		}
		else
			ft_putchar(s[i],1);
	}
	va_end(ap);
	return (len);
}

#include <stdio.h>

int main()
{
//	%d
	int	a = 2147483647;
	int b1 = printf("printf: %d\n", a);
	int c1 = ft_printf("printf: %d\n",a);
	printf("%d, %d \n",b1,c1);
//	%%
 	int a2 = ft_printf("ft: %%%b\n");
	int b2 = printf("pf: %%%b\n");
	printf("%d %d \n", a2, b2);
/*	return value of "%" ==> 0
	int a = printf("%");
	printf("%d",a);
*/
}
