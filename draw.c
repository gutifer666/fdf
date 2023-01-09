/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:36:29 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/09 11:08:58 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	zoom(t_point *point, float *x1, float *y1, t_fdf *data)
{
	point->x = point->x * data->zoom;
	point->y = point->y * data->zoom;
	*x1 = *x1 * data->zoom;
	*y1 = *y1 * data->zoom;
}

void	shitfting(t_point *point, float *x1, float *y1, t_fdf *data)
{
	point->x += data->shifting_x;
	point->y += data->shifting_y;
	*x1 += data->shifting_x;
	*y1 += data->shifting_y;
}

void	draw_line(t_point point, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)point.y][(int)point.x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	zoom(&point, &x1, &y1, data);
	if (z || z1)
		data->color = 0xFF0000;
	else
		data->color = 0x00FF00;
	isometric(&point.x, &point.y, z);
	isometric(&x1, &y1, z1);
	shitfting(&point, &x1, &y1, data);
	x_step = x1 - point.x;
	y_step = y1 - point.y;
	max = fmaxf(fabsf(x_step), fabsf(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(point.x - x1) || (int)(point.y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point.x, point.y, data->color);
		point.x += x_step;
		point.y += y_step;
	}
}

void	draw(t_fdf *data)
{
	t_point	point;

	point.y = 0;
	while (point.y < data->height)
	{
		point.x = 0;
		while (point.x < data->width)
		{
			if (point.x < data->width - 1)
				draw_line(point, point.x + 1, point.y, data);
			if (point.y < data->height - 1)
				draw_line(point, point.x, point.y + 1, data);
			point.x++;
		}
		point.y++;
	}
}
