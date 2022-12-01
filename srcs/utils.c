/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:46:25 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/01 09:59:56 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color(t_map *m, int x2, int y2)
{
	if (m->tab[m->y][m->x] > 100 || m->tab[y2][x2] > 100)
		m->color = 0xFFFFFF;
	else if (m->tab[m->y][m->x] > 60 || m->tab[y2][x2] > 60)
		m->color = 0x623509;
	else if (m->tab[m->y][m->x] > 40 || m->tab[y2][x2] > 40)
		m->color = 0xB0855A;
	else if (m->tab[m->y][m->x] > 10 || m->tab[y2][x2] > 10)
		m->color = 0xAC7339;
	else if (m->tab[m->y][m->x] > 0 || m->tab[y2][x2] > 0)
		m->color = 0x6AA84F;
	else if (m->tab[m->y][m->x] > -10 || m->tab[y2][x2] > -10)
		m->color = 0x2986CC;
	else
		m->color = 0x0061AB;
}

void	ft_print_controls(t_map *m)
{
	mlx_string_put(m->mlx, m->win, 10, 5, 0xFFFFFF, "Arrow: move map");
	mlx_string_put(m->mlx, m->win, 10, 25, 0xFFFFFF, "+ / -: zoom");
	mlx_string_put(m->mlx, m->win, 10, 45, \
	0xFFFFFF, "m / n: increase / decrease height");
	mlx_string_put(m->mlx, m->win, 10, 65, 0xFFFFFF, "  r  : reset");
}

char	**ft_free_tab(char **tab)
{
	while (*tab)
		free(*tab++);
	//free(tab);
	return (NULL);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}