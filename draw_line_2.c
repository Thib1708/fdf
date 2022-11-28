/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:13:12 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/28 13:13:23 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	segment_o4(int x1, int y1, int x2, int y2, t_map *map)
{
	int dx;
	int dy;
	int eps;

	dx = x1 - x2;
	dy = y2 - y1;
	eps = 0;
	
	while (x2 <= x1)
	{
		mlx_pixel_put(map->mlx, map->win, x1, y1, map->color); //VERT
		eps += dy;
		if ((eps * 10) >= dy)
		{
			y1++;
			eps -= dx;
		}
		x1--;
	}
}

void	segment_o5(int x1, int y1, int x2, int y2, t_map *map)
{
	int dx;
	int dy;
	int eps;

	dx = x1 - x2;
	dy = y1 - y2;
	eps = 0;
	while (x2 <= x1)
	{
		mlx_pixel_put(map->mlx, map->win, x1, y1, map->color); //CYAN
		eps += dy;
		if ((eps * 10) >= dy)
		{
			y1--;
			eps -= dx;
		}
		x1--;
	}
}

void	segment_o6(int x1, int y1, int x2, int y2, t_map *map)
{
	int dx;
	int dy;
	int eps;

	dx = x1 - x2;
	dy = y1 - y2;
	eps = 0;
	while (y2 <= y1)
	{
		mlx_pixel_put(map->mlx, map->win, x1, y1, map->color); //BLEU
		eps += dx;
		if ((eps * 10) >= dx)
		{
			x1--;
			eps -= dy;
		}
		y1--;
	}
}

void	segment_o7(int x1, int y1, int x2, int y2, t_map *map)
{
	int dx;
	int dy;
	int eps;

	dx = x2 - x1;
	dy = y1 - y2;
	eps = 0;
	while (y2 <= y1)
	{
		mlx_pixel_put(map->mlx, map->win, x1, y1, map->color); //violet
		eps += dx;
		if ((eps * 10) >= dx)
		{
			x1++;
			eps -= dy;
		}
		y1--;
	}
}

void	segment_o8(int x1, int y1, int x2, int y2, t_map *map)
{
	int dx;
	int dy;
	int eps;

	dx = x2 - x1;
	dy = y1 - y2;
	eps = 0;
	while (x1 <= x2)
	{
		mlx_pixel_put(map->mlx, map->win, x1, y1, map->color); //rose
		eps += dy;
		if ((eps * 10) >= dx)
		{
			y1--;
			eps -= dx;
		}
		x1++;
	}
}