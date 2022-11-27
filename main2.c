/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:04:49 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/27 11:41:27 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_fill_map(char *line, t_map *map, int i)
{
	char **split_line;
	int j;

	map->tab[i] = malloc(sizeof(int) * (map->length));
	split_line = ft_split(line, " \n");
	free(line);
	j = 0;
	while(split_line[j])
	{
		map->tab[i][j] = ft_atoi(split_line[j]);
		j++;
	}
}

void ft_get_map(t_win *param, t_map *map, char *file)
{
	char *line;
	int i;

	i = 0;
	ft_check_map(param, map);
	param->fd = open(file, O_RDONLY);
	while(get_next_line(param->fd, &line))
	{
		ft_fill_map(line, map, i);
		free(line);
		i++;
	}
}

t_map	*init_map(void)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->length = 0;
	map->depth = 0;
	map->offset_x = 0;
	map->offset_y = 0;
	map->start_x = 0;
	map->start_y = 0;
	return (map);
}

t_win		*init_param(char *file_name)
{
	t_win *param; 
	char *win_name;

	win_name = ft_strjoin("fdf ", file_name);
	if (!win_name)
		return (NULL);
	param = (t_win *)malloc(sizeof(t_win));
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 1300, 800, win_name);
	param->color = 0xFFFFFF;
	return (param);
}

int main(int argc, char **argv)
{
	t_win *param;
	t_map *map;
	
	int i = 0, j = 0;
	if (ft_check_arg(argc, argv))
		return (1);
	map = init_map();
	if (!map)
		return (1);
	param = init_param(argv[1]);
	if (!param)
		return (1);
	ft_read_file(argv[1], param);
	ft_check_map(param, map);
	ft_get_map(param, map, argv[1]);
	ft_create_map(param, map);
	ft_printf("\n\n\n\n");
	mlx_loop(param->mlx);
	return (0);
}