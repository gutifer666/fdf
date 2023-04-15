/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:32:29 by frgutier          #+#    #+#             */
/*   Updated: 2023/04/15 12:18:43 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Utiliza una ruta de fichero válida: ./fdf <file_path>\n");
		exit(1);
	}
	if (open(argv[0], O_RDONLY) == -1)
	{
		perror("Error al abrir el fichero:");
		close(open(argv[0], O_RDONLY));
		exit(1);
	}
}

void	leaks(void)
{
	system("leaks -q fdf");
}

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
