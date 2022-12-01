# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:12:25 by tgiraudo          #+#    #+#              #
#    Updated: 2022/12/01 13:24:08 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

FLAGS		= -Wall -Wextra -Werror

CC 			= cc

FRAMWORK 	= -framework OpenGL -framework Appkit

HEADER_PATH	= include/

HEADER		= ${HEADER_PATH}fdf.h

INCLUDES 	= -I ${HEADER_PATH}

MLX 		= -L ./mlx -lmlx

LIBFT 		= -L ./libft -lft 

SRCS		=	srcs/main.c 			\
				srcs/ft_check.c 		\
				srcs/ft_create_map.c	\
				srcs/utils.c 			\
				srcs/parsing.c			\
				srcs/hook.c				\
				
OBJS		= ${SRCS:.c=.o}

%.o 		: %.c ${HEADER} Makefile
				${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ 

${NAME}		: ${OBJS}
				${MAKE} -C ./mlx
				${MAKE} -C ./libft
				${CC} ${FLAGS} ${OBJS} ${LIBFT} $(MLX) ${FRAMWORK} -o ${NAME}



all			: ${NAME}

clean		:
				rm -f ${OBJS}

fclean		: clean
				${MAKE} clean -C ./mlx
				${MAKE} fclean -C ./libft
				rm -f ${NAME}

re			: fclean all

.PHONY		: all clean fclean re