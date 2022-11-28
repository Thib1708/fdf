# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:12:25 by tgiraudo          #+#    #+#              #
#    Updated: 2022/11/28 13:39:09 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c 			\
			ft_check.c 		\
			ft_create_map.c \
			draw_line_1.c 	\
			draw_line_2.c 	\
			utils.c 		\
			error.c 		\

NAME		= fdf

OBJS		= ${SRCS:.c=.o}

INCLUDES = -I .

HEADER 	= fdf.h

FLAGS = -Wall -Wextra -Werror

%.o : %.c ${HEADER}
	cc ${FLAGS} ${INCLUDES} -c $< -o $@ 

${NAME}: ${OBJS}
		${MAKE} -C ./mlx
		${MAKE} -C ./libft
		cc ${FLAGS} ${OBJS} -L ./mlx -lmlx -L ./libft -lft -framework OpenGL -framework Appkit -o ${NAME}



all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re