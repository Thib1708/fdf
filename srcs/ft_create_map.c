/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:55:34 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/06 13:30:08 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_position_iso(t_map *m, int x2, int y2)
{
	m->x1 = m->start_x + (m->offset * (m->x - m->y)) / sqrt(2);
	m->y1 = m->start_y - (m->tab[m->y][m->x] * m->alt)
		+ (m->offset * (m->x + m->y)) / sqrt(6);
	m->x2 = m->start_x + ((m->offset * x2) - (m->offset * y2))
		/ sqrt(2);
	m->y2 = m->start_y - (m->tab[y2][x2] * m->alt)
		+ ((m->offset * x2) + (m->offset * y2)) / sqrt(6);
	ft_color(m, x2, y2);
}

void	ft_draw_line(t_map *map)
{
	double	dx;
	double	dy;
	int		eps;
	double	x;
	double	y;

	dx = map->x2 - map->x1;
	dy = map->y2 - map->y1;
	eps = sqrt((dx * dx) + (dy * dy));
	dx /= eps;
	dy /= eps;
	x = map->x1;
	y = map->y1;
	while (eps--)
	{
		if ((int)y * map->win_l + (int)x < map->win_l * map->win_h
			&& x < map->win_l && x > 0 && y > 0 && y < map->win_h)
			map->img.data[(int)y * 2570 + (int)x] = map->color;
		x += dx;
		y += dy;
	}
}

void	ft_draw(t_map *map, int x, int y)
{
	map->x = x;
	map->y = y;
	if (map->depth - 1 != y)
	{
		ft_position_iso(map, x, y + 1);
		ft_draw_line(map);
	}
	if (map->length - 1 != x)
	{
		ft_position_iso(map, x + 1, y);
		ft_draw_line(map);
	}
}

void	ft_draw_map(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	m->img.img_ptr = mlx_new_image(m->mlx, 2570, 1440);
	m->img.data = (int *)mlx_get_data_addr(m->img.img_ptr,
			&m->img.bpp, &m->img.size_l, &m->img.endian);
	while (m->depth > y)
	{
		x = 0;
		while (m->length > x)
		{
			ft_draw(m, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img.img_ptr, 0, 0);
	ft_print_controls(m);
}

void	ft_create_map(t_win *w, t_map *m)
{
	m->mlx = w->mlx;
	m->win = w->win;
	ft_draw_map(m);
	mlx_key_hook(m->win, hook_key, m);
	mlx_mouse_hook(m->win, hook_mouse, m);
	mlx_hook(m->win, 17, 0, ft_exit, m);
}
