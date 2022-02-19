/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:07:52 by yohwang           #+#    #+#             */
/*   Updated: 2022/02/19 17:17:47 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putstr_len(char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	} else {
		return (0);
	}
}
// 다시 할 것!
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
		
