/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:35:14 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/30 16:45:47 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_fdf *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC){
		free(data);
		system("leaks fdf");
		ft_printf("Fin del programa\n");
		exit(0);
	}
	if (keycode == ARROW_UP)
		data->shifting_y -= 10;
	if (keycode == ARROW_DOWN)
		data->shifting_y += 10;
	if (keycode == ARROW_LEFT)
		data->shifting_x -= 10;
	if (keycode == ARROW_RIGHT)
		data->shifting_x += 10;
	if (keycode == KEY_PLUS)
		data->zoom += 10;
	if (keycode == KEY_MINUS)
		data->zoom -= 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
