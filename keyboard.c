/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:35:14 by frgutier          #+#    #+#             */
/*   Updated: 2023/04/15 14:05:59 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shifting_keys(int keycode, t_fdf *data)
{
	if (keycode == ARROW_UP)
		data->shifting_y -= 10;
	if (keycode == ARROW_DOWN)
		data->shifting_y += 10;
	if (keycode == ARROW_LEFT)
		data->shifting_x -= 10;
	if (keycode == ARROW_RIGHT)
		data->shifting_x += 10;
}

void	zoom_keys(int keycode, t_fdf *data)
{
	if (keycode == KEY_PLUS)
		data->zoom += 10;
	if (keycode == KEY_MINUS)
		data->zoom -= 10;
}

void	rotation_keys(int keycode, t_fdf *data)
{
	if (keycode == KEY_W)
		data->rot_x += 0.1;
	if (keycode == KEY_S)
		data->rot_x -= 0.1;
	if (keycode == KEY_A)
		data->rot_y += 0.1;
	if (keycode == KEY_D)
		data->rot_y -= 0.1;
}

int	key_hook(int keycode, t_fdf *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_R)
	{
		data->shifting_x = 500;
		data->shifting_y = 500;
		data->zoom = 20;
		data->rot_x = 0;
		data->rot_y = 0;
	}
	shifting_keys(keycode, data);
	zoom_keys(keycode, data);
	rotation_keys(keycode, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
