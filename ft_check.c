/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:46:54 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/27 11:48:59 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_check_map(t_win *param, t_map *map)
{
	char *line;
	char **split_line;
	
	while(get_next_line(param->fd, &line))
	{
		split_line = ft_split(line, " \n");
		free(line);
		if (ft_check_line(split_line))
			return ;
		if(!map->length)
			map->length = ft_tablen(split_line);
		if (map->length != ft_tablen(split_line))
			return (ft_putstr_fd("Toute les lignes doivent etre de meme taille.", 1));
		ft_free_tab(&split_line);
		map->depth++;
	}
	close(param->fd);
	map->offset_x = round(1300/((map->length + map->depth - 2) * 0.82));
	map->offset_y = round(1300/((map->length + map->depth - 2) * 0.82));
	map->start_x = 550;
	map->start_x++;
	map->start_y = 10;
	map->tab = malloc(sizeof(int *) * map->depth);
	if(map->tab)
		error_malloc();
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
				ft_putstr("Fichier non valide : caractere non numerique");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	ft_read_file(char *file, t_win *param)
{
	param->fd = open(file, O_RDONLY);
	if (param->fd < 0)
	{
		ft_putstr("Le fichier ne peut pas etre lu.");
		exit(1);
	}
}

int ft_check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr("Veuillez rentrer une map.");
		if (argc > 2)
			ft_putstr("Veuillez n'entrer qu'une map.");
		return (1);
	}
	return (0);
}