/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:27:27 by frgutier          #+#    #+#             */
/*   Updated: 2022/12/31 07:47:35 by frgutier         ###   ########.fr       */
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
	
	void	*mlx_ptr;
	void	*win_ptr;
}	fdf;

void    read_map(char *file_name, fdf *data); // Función que lee el fichero y guarda los datos en la estructura data
#endif