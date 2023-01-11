/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:53:36 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/11 10:52:43 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_point *s_point, t_point *f_point)
{
	float	previous_x;
	float	previous_y;

	previous_x = s_point->x;
	previous_y = s_point->y;
	s_point->x = (previous_x - previous_y) * cos(0.523599);
	s_point->y = -s_point->z + (previous_x + previous_y) * sin(0.523599);
	previous_x = f_point->x;
	previous_y = f_point->y;
	f_point->x = (previous_x - previous_y) * cos(0.523599);
	f_point->y = -f_point->z + (previous_x + previous_y) * sin(0.523599);
}

void	zoom(t_point *s_point, t_point *f_point, t_fdf *data)
{
	s_point->x = s_point->x * data->zoom;
	s_point->y = s_point->y * data->zoom;
	f_point->x = f_point->x * data->zoom;
	f_point->y = f_point->y * data->zoom;
}

void	shitfting(t_point *s_point, t_point *f_point, t_fdf *data)
{
	s_point->x += data->shifting_x;
	s_point->y += data->shifting_y;
	f_point->x += data->shifting_x;
	f_point->y += data->shifting_y;
}
