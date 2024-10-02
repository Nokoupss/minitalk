# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 14:15:20 by nbelkace          #+#    #+#              #
#    Updated: 2024/01/31 12:08:00 by nbelkace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_isalnum.c  ft_isdigit.c ft_memcmp.c     ft_atoi.c \
		ft_memset.c   ft_strlcat.c ft_strncmp.c    ft_tolower.c \
		ft_bzero.c 	  ft_isalpha.c ft_isprint.c    ft_putstr_fd.c \
		ft_strchr.c	  ft_toupper.c ft_putchar_fd.c ft_putnbr_fd.c \
		ft_calloc.c   ft_isascii.c ft_memmove.c    ft_putendl_fd.c \
		ft_strdup.c   ft_strlen.c  ft_substr.c     ft_memcpy.c \
		ft_strnstr.c  ft_memchr.c  ft_strrchr.c    ft_strlcpy.c \
		ft_strtrim.c  ft_strjoin.c ft_strmapi.c    ft_itoa.c \
		ft_striteri.c ft_split.c   ft_putchar.c    ft_putstr.c \

SRCS_PRINTF =	ft_printf/ft_itoa_base_address.c ft_printf/ft_itoa_base.c \
				ft_printf/ft_printaddress.c ft_printf/ft_printf.c \
				ft_printf/ft_printnbr.c

SRCS_GNL =	get_next_line/get_next_line_utils.c get_next_line/get_next_line.c

OBJS = $(SRCS:.c=.o) $(SRCS_PRINTF:.c=.o) $(SRCS_GNL:.c=.o)

INCLUDE = libft.h

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re
