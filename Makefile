# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:12:25 by tgiraudo          #+#    #+#              #
#    Updated: 2022/11/26 20:13:20 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I ./

1: Makefile
		${MAKE} -C ./mlx
		${MAKE} -C ./libft
		cc -g3 main.c -I . -L ./mlx -lmlx -L ./libft -lft -framework OpenGL -framework Appkit

2: Makefile
		${MAKE} -C ./mlx
		${MAKE} -C ./libft
		cc -g3 main2.c utils.c ft_check.c draw_line.c ft_create_map.c -L ./mlx -lmlx -L ./libft -lft -framework OpenGL -framework Appkit

3: Makefile
		${MAKE} -C ./mlx
		${MAKE} -C ./libft
		cc -g3 main3.c utils.c -I . -L ./mlx -lmlx -L ./libft -lft -framework OpenGL -framework Appkit