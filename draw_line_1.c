/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:02:29 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/28 13:12:45 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	segment_o1(int x1, int y1, int x2, int y2, t_map *map)
{
	int dx;
	int dy;
	int eps;

	dx = x2 - x1;
	dy = y2 - y1;
	eps = 0;
	while (x1 <= x2)
	{
		mlx_pixel_put(map->mlx, map->win, x1, y1, map->color); //BLANC
		eps += dy;
		if ((eps * 10) >= dx)
		{
			y1++;
			eps -= dx;
		}
		x1++;
	}
}

void	segment_o2(int x1, int y1, int x2, int y2, t_map *map)
{
	int dx;
	int dy;
	int eps;

	dx = x2 - x1;
	dy = y2 - y1;
	eps = 0;
	while (y1 <= y2)
	{
		mlx_pixel_put(map->mlx, map->win, x1, y1, map->color); //ROUGE
		eps += dx;
		if ((eps * 10) >= dy)
		{
			x1++;
			eps -= dy;
		}
		y1++;
	}
}

void	segment_o3(int x1, int y1, int x2, int y2, t_map *map)
{
	int dx;
	int dy;
	int eps;

	dx = x1 - x2;
	dy = y2 - y1;
	eps = 0;
	while (y1 <= y2)
	{
		mlx_pixel_put(map->mlx, map->win, x1, y1, map->color); //JAUNE
		eps += dx;
		if ((eps * 10) >= dx)
		{
			x1--;
			eps -= dy;
		}
		y1++;
	}
}

void segment(t_map *map)
{
	double m;
	
	if(map->x1 == map->x2)
	{
		if(map->y1 < map->y2)
			segment_o3(map->x1, map->y1, map->x2, map->y2, map);
		else
			segment_o7(map->x1, map->y1, map->x2, map->y2, map);
		return ;
	}
	m = (float)(map->y2 - map->y1)/(map->x2 - map->x1);
	if(0 <= m && m <= 1 && map->x1 <= map->x2)
		segment_o1(map->x1, map->y1, map->x2, map->y2, map);
	else if(0 > m && m >= -1 && map->x1 <= map->x2)
		segment_o8(map->x1, map->y1, map->x2, map->y2, map);
	else if(m < -1 && map->y2 <= map->y1)
		segment_o7(map->x1, map->y1, map->x2, map->y2, map);
	else if(m > 1 && map->y2 <= map->y1)
		segment_o6(map->x1, map->y1, map->x2, map->y2, map);
	else if(0 < m && m <= 1 && map->x2 <= map->x1)
		segment_o5(map->x1, map->y1, map->x2, map->y2, map);
	else if(m <= 0 && m >= -1 && map->x2 <= map->x1)
		segment_o4(map->x1, map->y1, map->x2, map->y2, map);
	else if(-1 > m && map->y1 <= map->y2)
		segment_o3(map->x1, map->y1, map->x2, map->y2, map);
	else
		segment_o2(map->x1, map->y1, map->x2, map->y2, map);
}