/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:06:40 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/27 11:49:36 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx/mlx.h"
#include <unistd.h>
#include "libft/headers/get_next_line.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/libft.h"
#include <math.h>

typedef struct s_map
{
	int		**tab;
	int		length;
	int		depth;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		offset_x;
	int		offset_y;
	int		start_x;
	int		start_y;
	void	*mlx;
	void	*win;
	int		color;
}	t_map;

typedef struct s_win
{
	void 	*mlx;
	void 	*win;
	int		fd;
	int		color;
	char	*file_name;
}	t_win;

int		ft_check_arg(int argc, char **argv);
void	ft_read_file(char *file, t_win *param);
void	ft_get_map(t_win *param, t_map *map, char *file);
void	ft_check_map(t_win *param, t_map *map);
int		ft_check_line(char **line);
int		ft_tablen(char **tab);
void	ft_draw_map(t_map *map);
void	ft_draw_line_h(t_map *map, int x, int y);
void	ft_draw_line_v(t_map *map, int x, int y);
void	ft_position(t_map *map, int xx1, int yy1, int xx2, int yy2);
void	segment(t_map *map);
void	segment_o1(int x1, int y1, int x2, int y2, t_map *map);
void	segment_o2(int x1, int y1, int x2, int y2, t_map *map);
void	segment_o3(int x1, int y1, int x2, int y2, t_map *map);
void	segment_o4(int x1, int y1, int x2, int y2, t_map *map);
void	segment_o5(int x1, int y1, int x2, int y2, t_map *map);
void	segment_o6(int x1, int y1, int x2, int y2, t_map *map);
void	segment_o7(int x1, int y1, int x2, int y2, t_map *map);
void	segment_o8(int x1, int y1, int x2, int y2, t_map *map);
int		hook_key(int key, t_map *map);
void	ft_create_map(t_win *param, t_map *map);
void	ft_free_tab(char ***tab);
void	error_malloc(void);

#endif