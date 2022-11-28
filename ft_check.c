/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:46:54 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/28 14:03:24 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_check_map(t_win *param, t_map *map)
{
	char *line;
	char **split_line;
	
	while(get_next_line(param->fd, &line))
	{
		split_line = ft_split(line, " \n");
		free(line);
		if (ft_check_line(split_line))
			return 1;
		if(!map->length)
			map->length = ft_tablen(split_line);
		if (map->length != ft_tablen(split_line))
			return (ft_putstr_fd("Error : diferent line's length", 1), 0);
		map->depth++;
	}
	close(param->fd);
	new_init_map(map);
	map->tab = malloc(sizeof(int *) * map->depth);
	if(!map->tab)
		return (ft_putstr_fd("Error : malloc", 1), 0);
	return (0);
}

int	ft_check_line(char **line)
{
	int i;
	int j;

	i = 0;
	while(line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if(ft_isdigit(line[i][j]) || line[i][j] == '-')
				j++;
			else
			{
				ft_putstr("Error : unvalid file");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	ft_read_file(char *file, t_win *param)
{
	param->fd = open(file, O_RDONLY);
	if (param->fd < 0)
	{
		ft_putstr("Error : file can't be read");
		return (0);
	}
	return (1);
}

int ft_check_arg(int argc)
{
	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr("Error : you had to enter a amp");
		if (argc > 2)
			ft_putstr("Error : you had to enter only one map");
		return (1);
	}
	return (0);
}