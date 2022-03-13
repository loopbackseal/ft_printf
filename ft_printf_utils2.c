/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:07:52 by yohwang           #+#    #+#             */
/*   Updated: 2022/03/13 16:43:32 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_len(char *s)
{
	char	*null;

	if (!s)
	{
		null = "(null)";
		write(1, null, ft_strlen(null));
		return (ft_strlen(null));
	} else {
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
}
//65 A 97 a
char	*ft_base(int flag)
{
	char	*hex;
	int		i;

	hex = malloc(16);
	if (!hex)
		return (0);
	i = 9;
	hex[0] = '0';
	hex[1] = '1';
	hex[2] = '2';
	hex[3] = '3';
	hex[4] = '4';
	hex[5] = '5';
	hex[6] = '6';
	hex[7] = '7';
	hex[8] = '8';
	hex[9] = '9';
	while (++i < 16)
		hex[i] = flag++;
	return hex;
}

int	ft_change2hex(unsigned long long i, char *hex, int flag)
{
	unsigned long long	tmp;
	char				num[17];
	int					len;
	int					idx;

	if (!hex)
		return (0);
	tmp = i;
	idx = 0;
	len = 0;
	if (flag == 2)
		write(1, "0x", 2);
	while (tmp > 15)
	{
		num[len] = hex[tmp % 16];
		len++;
		tmp = tmp / 16;
	}
	num[len] = hex[tmp];
	idx = len + 1;
	free(hex);
	hex = 0;
	while (len >= 0)
		write(1, &num[len--], 1);
	return (idx + flag);
}

int	ft_change2hex2(int n, char *hex)
{
	unsigned long	num;
	unsigned long	tmp;
	char			result[17];
	int				len;
	int				idx;

	if (!hex)
		return (0);
	if (n >= 0)
		num = n;
	else
		num = 4294967296 + n;
	tmp = num;
	idx = 0;
	len = 0;
	while (tmp > 15)
	{
		result[len] = hex[tmp % 16];
		len++;
		tmp = tmp / 16;
	}
	result[len] = hex[tmp];
	idx = len + 1;
	free(hex);
	while (len >= 0)
		write(1, &result[len--], 1);
	return (idx);
}


int ft_putunsigned_len(int n)
{
	unsigned long	num;
	unsigned long	tmp;
	int					len;
	char				c;

	if (n >= 0)
		num = n;
	else
		num = 4294967296 + n;
	tmp = num;
	len = count_len(num);
	while (len > 0)
	{
		c = num / calc_len(len) + '0';
		write(1, &c, 1);
		num = num % calc_len(len);
		len--;
	}
	c = num + '0';
	write(1, &c, 1);
	return (count_len(tmp) + 1);
}
