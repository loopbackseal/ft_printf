/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:31:45 by yohwang           #+#    #+#             */
/*   Updated: 2022/03/13 17:10:37 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printf(const char *s, ...);
int			ft_putchar_len(char c);
size_t		ft_strlen(const char *s);
long long	count_len(long long n);
long long	calc_len(long long len);
void		ft_putnbr_fd(int n, int fd);
int			ft_putstr_len(char *s);
char		*ft_base(int flag);
int			ft_change2hex(unsigned long long i, char *hex);
int			ft_putunsigned_len(int n);
int			ft_change2hex2(int i, char *hex);
#endif
