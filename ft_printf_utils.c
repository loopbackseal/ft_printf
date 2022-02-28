/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:26:50 by yohwang           #+#    #+#             */
/*   Updated: 2022/02/28 12:22:34 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

long long	count_len(long long n)
{
	long long	len;

	len = 1;
	while (n / 10 > 0)
	{
		len++;
		n = n / 10;
	}
	return (len - 1);
}

long long	calc_len(long long len)
{
	long long	ten;

	ten = 1;
	while (len-- > 0)
		ten = ten * 10;
	return (ten);
}

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long long	num;
	long long	len;

	if (fd > 0)
	{
		if (n < 0)
		{
			c = '-';
			write(fd, &c, 1);
			num = -1LL * n;
		}
		else
			num = n;
		len = count_len(num);
		while (len > 0)
		{
			c = num / calc_len(len) + '0';
			write(fd, &c, 1);
			num = num % calc_len(len);
			len--;
		}
		c = num + '0';
		write(fd, &c, 1);
	}
}
