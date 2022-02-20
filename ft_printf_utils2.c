/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:07:52 by yohwang           #+#    #+#             */
/*   Updated: 2022/02/20 13:58:58 by yohwang          ###   ########.fr       */
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
/* 다시 할 것!
int	ft_putptr_len(int s)
{
	if (s)
	{
		write(1, &s, ft_strlen(&s));
		return (ft_strlen(&s));
	} else {
		return (0);
	}
}
*/		
