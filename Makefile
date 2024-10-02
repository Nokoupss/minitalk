# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadjy <nadjy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 04:00:26 by nadjy             #+#    #+#              #
#    Updated: 2024/09/27 11:34:44 by nadjy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

# Directory
SRCS = srcs
UTILS = utils

# Utils Directory
UTILS_C = $(SRCS)/$(UTILS)

# Source Files
SRCS_CLIENT =	${SRCS}/client.c
SRCS_SERVER =	${SRCS}/server.c
			
# Object FIles
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}

# Archive and Libraries
LIBFT = $(UTILS_C)/libft/libft.a

# Compiler and Flags
CC = cc
FLAGS = -Wall -Wextra -Werror -g3

# Remove command
RM = rm -f

# Rules
all : ${NAME_CLIENT} ${NAME_SERVER} 

${NAME_CLIENT} : ${OBJS_CLIENT}
	make -C $(UTILS_C)/libft
	${CC} -o ${NAME_CLIENT} ${OBJS_CLIENT} ${LIBFT} -I includes

${NAME_SERVER} : ${OBJS_SERVER}
	make -C $(UTILS_C)/libft
	${CC} -o ${NAME_SERVER} ${OBJS_SERVER} ${LIBFT} -I includes

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean :
	make -C $(UTILS_C)/libft clean
	${RM} ${OBJS_CLIENT} ${OBJS_SERVER}

fclean : clean
	make -C $(UTILS_C)/libft fclean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}

re : fclean all

.PHONY: all clean fclean re