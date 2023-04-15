/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:36:29 by frgutier          #+#    #+#             */
/*   Updated: 2023/04/15 14:12:13 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point s_point, t_point final_point, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;

	s_point.z = data->z_matrix[(int)s_point.y][(int)s_point.x];
	final_point.z = data->z_matrix[(int)final_point.y][(int)final_point.x];
	rotation(&s_point, &final_point, data);
	zoom(&s_point, &final_point, data);
	data->color = 0xFF0000;
	isometric(&s_point, &final_point);
	shitfting(&s_point, &final_point, data);
	x_step = final_point.x - s_point.x;
	y_step = final_point.y - s_point.y;
	max = fmaxf(fabsf(x_step), fabsf(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(s_point.x - final_point.x) || (int)(s_point.y - final_point.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, s_point.x,
			s_point.y, data->color);
		s_point.x += x_step;
		s_point.y += y_step;
	}
}

void	draw(t_fdf *data)
{
	t_point	starting_point;
	t_point	final_point;

	starting_point.y = 0;
	while (starting_point.y < data->height)
	{
		starting_point.x = 0;
		while (starting_point.x < data->width)
		{
			if (starting_point.x < data->width - 1)
			{
				final_point.x = starting_point.x + 1;
				final_point.y = starting_point.y;
				draw_line(starting_point, final_point, data);
			}
			if (starting_point.y < data->height - 1)
			{
				final_point.x = starting_point.x;
				final_point.y = starting_point.y + 1;
				draw_line(starting_point, final_point, data);
			}
			starting_point.x++;
		}
		starting_point.y++;
	}
}
