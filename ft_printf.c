/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:31:35 by yohwang           #+#    #+#             */
/*   Updated: 2022/02/06 18:56:24 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(char c, va_list ap)
{
//	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
	int ju = va_arg(ap, int);
	char jeon = ju + '0';
	write(1, &jeon, 1);
//	else if (c == 'c' || c == '%')
//	int jujeon = va_arg(ap, int);	
//	write(1, &jujeon, 1);
//	else if (c == 's')
//		write(1, va_arg(ap, int), 1);
//	else if (c == 'p')
//		write(1, va_arg(ap, int), 1);
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
		{
			check_format(s[++i], ap);
			i++;
		}
		else
			write(1, &s[i++], 1);
	}
	return (len);
}
#include <stdio.h>

int main()
{
	int c = 7;
	ft_printf("asdf%d\n", c);
	int i = printf("%1");
	printf("%d", i);
}
