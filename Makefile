# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 14:42:46 by yohwang           #+#    #+#              #
#    Updated: 2022/02/06 14:49:52 by yohwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	ft_printf.c ft_printf_utils.c
OBJ		=	$(SRC:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
.PHONY	:	all clean fclean re
all		:	$(NAME)
$(NAME)	:	$(OBJ)
	ar -rc $@ $^
%.o		:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<
clean	:
	@rm -f $(OBJ)
fclean	:	clean
	@rm -f $(NAME)
re		:	fclean all
