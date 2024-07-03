# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: felricha <felricha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 16:03:26 by felricha          #+#    #+#              #
#    Updated: 2024/04/18 12:49:34 by felricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
CC 				= gcc
RM				= rm -f
CFLAGS 			= -c -Wall -Wextra -Werror
INCLUDES		= -I.
LIBFT			= ./libft/libft.a
SRCS			= ft_putchar_pf.c ft_putstr_pf.c ft_printf.c ft_puthex_pf.c \
					ft_putnbr_pf.c ft_unsigned_pf.c ft_printptr_pf.c ft_putnbrbase_pf.c
OBJS			= $(SRCS:.c=.o)
# BONUS			=	
# BONUS_OBJS		= $(BONUS:.c=.o)

$(NAME):		$(OBJS)
				$(MAKE) bonus -C ./libft
				cp libft/libft.a $(NAME)
				$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:
				$(MAKE) clean -C ./libft
				rm -rf $(BONUS)
				rm -rf $(OBJS)


fclean:			clean
				$(MAKE) fclean -C ./libft
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY: all clean fclean re