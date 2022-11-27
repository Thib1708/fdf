/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:46:25 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/27 11:47:16 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_tablen(char **tab)
{
	int i;
	while(tab[i])
		i++;
	return (i);
}

int	hook_key(int key, t_map  *map)
{
	if (key == 53)
		exit(0);
	if (key == 126)
		map->start_y -= 20;
	if	(key == 125)
		map->start_y += 20;
	if (key == 123)
		map->start_x -= 20;
	if	(key == 124)
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
	printf("%d ", key);
	mlx_clear_window(map->mlx, map->win);
	ft_draw_map(map);
	return (0);
}

void	ft_free_tab(char ***tab)
{
		while (*tab)
	{
		free(*tab++);
	}
	free(tab);
	*tab = NULL;
}