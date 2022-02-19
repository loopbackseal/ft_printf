/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:31:45 by yohwang           #+#    #+#             */
/*   Updated: 2022/02/19 15:13:55 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
int			ft_putchar_len(char c);
size_t		ft_strlen(const char *s);
long long	count_len(long long n);
long long	calc_len(long long len);
void		ft_putnbr_fd(int n, int fd);
int			ft_putstr_len(char *s);
#endif
