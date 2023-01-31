/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:52:23 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/31 08:29:40 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		check_fd;

	if (argc == 2)
	{
		check_fd = 0;
		data = (t_fdf *)malloc(sizeof(t_fdf));
		read_map(argv[1], data, &check_fd);
		init(data);
		draw(data);
		mlx_key_hook(data->win_ptr, key_hook, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_printf("Error: Wrong number of arguments\n");
	return (0);
}
