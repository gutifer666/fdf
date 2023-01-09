/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:36:29 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/09 08:36:13 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    isometric(float *x, float *y, int z)
{
    float previous_x;
    float previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void    draw_line(float x, float y, float x1, float y1, fdf *data)
{
    float x_step;
    float y_step;
    float max;
    int z;
    int z1;

    z = data->z_matrix[(int)y][(int)x];
    z1 = data->z_matrix[(int)y1][(int)x1];
 
    x = x * data->zoom;
    y = y * data->zoom;
    x1 = x1 * data->zoom;
    y1 = y1 * data->zoom;

    data->color = (z || z1) ? 0xFF0000 : 0x00FF00;

    // 2D to 3D
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);

    // Side scrolling
    x += data->shifting_x;
    y += data->shifting_y;
    x1 += data->shifting_x;
    y1 += data->shifting_y;
    
    x_step = x1 - x;
    y_step = y1 - y;
    max = fmaxf(fabsf(x_step), fabsf(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color); 
        x += x_step;
        y += y_step;
    }
}

void    draw(fdf *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                draw_line(x, y, x + 1, y, data);
            if (y < data->height - 1)
                draw_line(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }

}