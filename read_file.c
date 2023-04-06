/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:13:02 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/21 20:08:41 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

void	get_map_dimensions(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	char	**word_grid;

	fd = open(file, O_RDONLY);
	data->height = 0;
	data->width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->height++;
		if (data->width == 0)
		{
			word_grid = ft_split(line, ' ');
			while (word_grid[data->width])
			{
				data->width++;
				//free(word_grid[data->width]);
			}
			free_split(word_grid);
		}			
		free(line);
	}
	close(fd);
}

void	allocate_z_matrix(t_fdf *data)
{
	int	i;

	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->z_matrix)
		return ;
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	data->z_matrix[i] = NULL;
}

void	setting_row(char *line, int *row)
{
	int		i;
	char	**word_grid;

	word_grid = ft_split(line, ' ');
	i = 0;
	while (word_grid[i])
	{
		row[i] = ft_atoi(word_grid[i]) * 10;
		free(word_grid[i]);
		i++;
	}
	free(word_grid);
}

void	fill_z_matrix(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		setting_row(line, data->z_matrix[i]);
		free(line);
		i++;
	}
	close(fd);
}

void	read_map(char *file_path, t_fdf *data)
{
	get_map_dimensions(file_path, data);
	allocate_z_matrix(data);
	fill_z_matrix(file_path, data);
}
