/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:52:23 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/28 20:18:04 by frgutier         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_fdf	*data;

	check_arguments(argc);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_map(argv[1], data);
	init(data);
	draw(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	system("leaks -q fdf");
	ft_printf("Fin del programa\n");
	mlx_loop(data->mlx_ptr);
	return (0);	
}
