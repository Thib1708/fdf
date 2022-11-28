/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:55:34 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/28 19:05:10 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_position(t_map *map, int xx1, int yy1, int xx2, int yy2)
{
	map->x1 = map->start_x + (map->offset_x * (xx1 - yy1)) / sqrt(2);
	map->y1 = map->start_y - (map->tab[yy1][xx1] * map->alt) + ((map->offset_x * xx1) + (map->offset_y * yy1)) / sqrt(6);
	map->x2 = map->start_x + ((map->offset_x * xx2) - (map->offset_y * yy2)) / sqrt(2);
	map->y2 = map->start_y - (map->tab[yy2][xx2] * map->alt) + ((map->offset_x * xx2) + (map->offset_y * yy2)) / sqrt(6);
	if (map->tab[yy2][xx2] <= 0 || map->tab[yy1][xx1] <= 0)
		map->color = 0x000CFF;
	else if (map->tab[yy2][xx2] <= 10 || map->tab[yy1][xx1] <= 10)
		map->color = 0x0C961F;
	else if (map->tab[yy2][xx2] <= 60 || map->tab[yy1][xx1] <= 60)
		map->color = 0xB0855A;
	else if (map->tab[yy2][xx2] <= 100 || map->tab[yy1][xx1] <= 100)
		map->color = 0x623509;
	else 
		map->color = 0xFFFFFF;
}

void	ft_draw_line_v(t_map *map, int x, int y)
{
	ft_position(map, x, y, x, y + 1);
	segment(map);
}

void	ft_draw_line_h(t_map *map, int x, int y)
{
	ft_position(map, x, y, x + 1, y);
	segment(map);
}

void	ft_draw_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	mlx_string_put(map->mlx, map->win, 10, 10, 0xFFFFFF, "ESC : Close window");
	mlx_string_put(map->mlx, map->win, 10, 35, 0xFFFFFF, "Fleche directionnel = deplacement");
	mlx_string_put(map->mlx, map->win, 10, 55, 0xFFFFFF, "+ = zoom +");
	mlx_string_put(map->mlx, map->win, 10, 75, 0xFFFFFF, "- = zoom -");
	while(map->depth > i)
	{
		j = 0;
		while(map->length > j)
		{
			if(map->depth  - 1 != i)
				ft_draw_line_v(map, j, i);
			if(map->length  - 1!= j)
				ft_draw_line_h(map, j, i);
			j++;
		}
		i++;
	}
}

void	ft_create_map(t_win *param, t_map *map)
{
	map->mlx = param->mlx;
	map->win = param->win;
	ft_printf("%d, ", map->win_l);
	ft_draw_map(map);
	mlx_key_hook(param->win, hook_key, map);
}