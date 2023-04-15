/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:32:29 by frgutier          #+#    #+#             */
/*   Updated: 2023/04/15 10:43:00 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_arguments(int argc)
{
	if (argc != 2)
	{
		ft_printf("Utiliza una ruta de fichero válida: ./fdf <file_path>\n");
		exit(1);
	}
}

void	leaks(void)
{
	system("leaks -q fdf");
}
