/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:23:21 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/01 09:48:02 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_map(char *line, t_map *map, int i)
{
	char	**split_line;
	int		j;

	map->tab[i] = malloc(sizeof(int) * (map->length));
	split_line = ft_split(line, " \n");
	free(line);
	j = 0;
	while (split_line[j])
	{
		map->tab[i][j] = ft_atoi(split_line[j]);
		free(split_line[j]);
		j++;
	}
	free(split_line);
}

void	ft_pars_map(t_win *param, t_map *map, char *file)
{
	char	*line;
	int		i;

	i = 0;
	if (ft_check_map(param, map))
		exit(1);
	param->fd = open(file, O_RDONLY);
	while (get_next_line(param->fd, &line))
	{
		ft_fill_map(line, map, i);
		i++;
	}
}
