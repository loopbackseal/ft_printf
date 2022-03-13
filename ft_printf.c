/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:31:35 by yohwang           #+#    #+#             */
/*   Updated: 2022/03/13 17:10:08 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(int i, va_list *ap, const char *s)
{
	long long	tmp;

	if (s[i] == 'd' || s[i] == 'i')
	{
		tmp = va_arg(*ap, int);
		ft_putnbr_fd(tmp, 1);
		if (tmp < 0)
			return (count_len(-tmp) + 2);
		else
			return (count_len(tmp) + 1);
	}
	else if (s[i] == 'c')
		return (ft_putchar_len(va_arg(*ap, int)));
	else if (s[i] == '%')
		return (ft_putchar_len('%'));
	else if (s[i] == 's')
		return (ft_putstr_len(va_arg(*ap, char *)));
	else if (s[i] == 'p')
		return (ft_change2hex(va_arg(*ap, unsigned long long), ft_base('x')));
	else if (s[i] == 'x' || s[i] == 'X')
		return (ft_change2hex2(va_arg(*ap, int), ft_base(s[i])));
	else if (s[i] == 'u')
		return (ft_putunsigned_len(va_arg(*ap, int)));
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
	len = ft_strlen(s);
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
