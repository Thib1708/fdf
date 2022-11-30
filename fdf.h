/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:06:40 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/30 13:11:47 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include <unistd.h>
# include "libft/headers/get_next_line.h"
# include "libft/headers/ft_printf.h"
# include "libft/headers/libft.h"
# include <math.h>

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}	t_img;

typedef struct s_map
{
	int		**tab;
	int		length;
	int		depth;
	int		win_l;
	int		win_h;
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		offset;
	int		start_x;
	int		start_y;
	void	*mlx;
	void	*win;
	int		color;
	float	alt;
	t_img	img;
}	t_map;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		fd;
	int		color;
	char	*file_name;
	int		win_l;
	int		win_h;
}	t_win;

/************************PARSING*************************/
void	ft_pars_map(t_win *w, t_map *m, char *file);
void	ft_fill_map(char *line, t_map *m, int i);

/*************************CHECK**************************/
int		ft_check_map(t_win *w, t_map *m);
int		ft_check_line(char **line);
int		ft_check_file(char *file, t_win *w);
int		ft_check_arg(int argc);

/************************CREATE*MAP**********************/
void	ft_position_iso(t_map *m, int xx2, int yy2);
void	ft_draw_line(t_map *m);
void	ft_draw(t_map *m, int x, int y);
void	ft_draw_map(t_map *m);
void	ft_create_map(t_win *w, t_map *m);

/*************************HOOKS**************************/
int		hook_key(int key, t_map *m);
void	move_offset(t_map *m, int i);
int		ft_exit(t_map *m);

/**************************MAIN**************************/
t_map	*init_map(void);
t_win	*init_win(char *file_name);
void	new_param_map(t_map *m);

/*************************UTILS**************************/
void	ft_color(t_map *m, int x2, int y2);
void	ft_print_controls(t_map *m);
char	**ft_free_tab(char **tab);
int		ft_tablen(char **tab);

#endif