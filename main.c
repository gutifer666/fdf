/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:52:23 by frgutier          #+#    #+#             */
/*   Updated: 2023/04/15 10:41:00 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;

	atexit(leaks);
	check_arguments(argc);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_map(argv[1], data);
	init(data);
	draw(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
