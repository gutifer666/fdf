/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:35:14 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/11 11:00:29 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_fdf *data)
{
	printf("keycode: %d\n", keycode);
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
