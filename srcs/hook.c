/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:41:05 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/30 12:42:00 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hook_key(int key, t_map *map)
{
	if (key == 53)
		ft_exit(map);
	if (key == 125)
		map->start_y -= 20;
	if (key == 126)
		map->start_y += 20;
	if (key == 124)
		map->start_x -= 20;
	if (key == 123)
		map->start_x += 20;
	if (key == 69)
		move_offset(map, 1);
	if (key == 78)
		move_offset(map, -1);
	if (key == 46)
		map->alt += 0.1;
	if (key == 45)
		map->alt -= 0.1;
	if (key == 15)
		new_param_map(map);
	mlx_destroy_image(map->mlx, map->img.img_ptr);
	ft_draw_map(map);
	return (0);
}

void	move_offset(t_map *map, int i)
{
	if (map->offset + i > 0)
		map->offset += i;
}

int	ft_exit(t_map *map)
{
	int	i;

	i = 0;
	while (map->depth > i)
	{
		free(map->tab[i]);
		i++;
	}
	mlx_destroy_window(map->mlx, map->win);
	free(map->tab);
	free(map);
	exit(0);
	return (0);
}
