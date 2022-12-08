/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:04:49 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/07 10:57:30 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_param_map(t_map *m)
{
	m->offset = round(m->win_l / (m->length + m->depth - 2));
	m->start_x = (m->win_l - ((m->length + m->depth)
				* m->offset) / sqrt(2)) / 2;
	m->start_x += m->depth * m->offset / sqrt(2);
	m->start_y = (m->win_h - (m->length * m->offset + m->depth
				* m->offset) / sqrt(6)) / 2;
	m->alt = 0.8;
}

t_map	*init_map(void)
{
	t_map	*m;

	m = malloc(sizeof(t_map));
	if (!m)
		return (ft_putstr_fd("Error : malloc", 1), NULL);
	m->length = 0;
	m->depth = 0;
	m->offset = 0;
	m->start_x = 0;
	m->start_y = 0;
	m->alt = 1;
	return (m);
}

t_win	*init_win(char *file_name)
{
	t_win	*w;
	char	*win_name;

	win_name = ft_strjoin("fdf ", file_name);
	if (!win_name)
		return (NULL);
	w = malloc(sizeof(t_win));
	if (!w)
		return (ft_putstr_fd("Error : malloc", 1), NULL);
	w->mlx = mlx_init();
	w->win_l = 2570;
	w->win_h = 1440;
	w->win = mlx_new_window(w->mlx, w->win_l, w->win_h, win_name);
	free(win_name);
	w->color = 0xFFFFFF;
	w->fd = open(file_name, O_RDONLY);
	return (w);
}

int	main(int argc, char **argv)
{
	t_win	*w;
	t_map	*m;

	if (!ft_check_arg(argc))
		return (1);
	if (!ft_check_file(argv[1]))
		return (1);
	w = init_win(argv[1]);
	if (!w)
		return (1);
	m = init_map();
	if (!m)
		return (1);
	m->win_l = w->win_l;
	m->win_h = w->win_h;
	ft_pars_map(w, m, argv[1]);
	ft_create_map(w, m);
	mlx_loop(w->mlx);
	return (0);
}
