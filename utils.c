/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:46:25 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/28 19:28:31 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_tablen(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
		i++;
	return (i);
}

int	hook_key(int key, t_map  *map)
{
	if (key == 53)
		exit(0);
	if (key == 125)
		map->start_y -= 20;
	if	(key == 126)
		map->start_y += 20;
	if (key == 124)
		map->start_x -= 20;
	if	(key == 123)
		map->start_x += 20;
	if	(key == 69)
	{
		map->offset_x += 1;
		map->offset_y += 1;
	}
	if	(key == 78)
	{
		map->offset_x -= 1;
		map->offset_y -= 1;
	}
	if (key == 46)
		map->alt += 0.1;
	if (key == 45)
		map->alt -= 0.1;
	if (key == 15)
		new_init_map(map);
	mlx_clear_window(map->mlx, map->win);
	ft_draw_map(map);
	return (0);
}

char	**ft_free_tab(char **tab)
{
	while (*tab)
	{
		free(*tab++);
	}
	free(tab);
	return (NULL);
}

void	new_init_map(t_map *map)
{
	ft_printf("%d, ", map->win_l);
	map->offset_x = round(map->win_l/((map->length + map->depth - 2) * 0.82));
	map->offset_y = round(map->win_l/((map->length + map->depth - 2) * 0.82));
	map->start_x = (map->win_l - ((map->length + map->depth) * map->offset_x) / sqrt(2)) / 2;
	map->start_x += map->depth * map->offset_x / sqrt(2);
	map->start_y = (map->win_h - (map->length * map->offset_x + map->depth * map->offset_x) / sqrt(6))/2;
	map->alt = 0.8;
}