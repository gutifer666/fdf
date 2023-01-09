/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:27:27 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/09 10:17:02 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include	"mlx/mlx.h"
# include	"libft/libft.h"
# include	<fcntl.h>
# include	<math.h>
# include	<stdio.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shifting_x;
	int		shifting_y;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
}	t_point;

void	read_map(char *file_name, t_fdf *data);
void	draw(t_fdf *data);
#endif