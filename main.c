/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:52:23 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/28 17:28:30 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

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

int	main(int argc, char **argv)
{
	t_fdf	*data;

	check_arguments(argc);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_map(argv[1], data);
	init(data);
	draw(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_loop(data->mlx_ptr);
	atexit(leaks);
	return (0);
}