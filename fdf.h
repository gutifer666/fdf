/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:27:27 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/07 13:00:49 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include	"mlx/mlx.h"
# include	"libft/libft.h"
# include	<fcntl.h>
# include	<math.h>
# include	<stdio.h>

typedef struct // Estructura que contiene los datos de la matriz de alturas y las dimensiones de la matriz de alturas y la ventana de la aplicación
{
	int	width;
	int	height;
	int **z_matrix;
	int	zoom;
	int color;
	
	void	*mlx_ptr;
	void	*win_ptr;
}	fdf;

void    read_map(char *file_name, fdf *data); // Función que lee el fichero y guarda los datos en la estructura data
void    draw_line(float x, float y, float x1, float y1, fdf *data); // Función que dibuja una línea entre dos puntos 
void    draw(fdf *data); // Función que dibuja la matriz de alturas
#endif