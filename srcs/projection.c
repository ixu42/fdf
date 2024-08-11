/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:03:46 by ixu               #+#    #+#             */
/*   Updated: 2024/08/11 15:19:28 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
	isometric projection:
	- rotate x, y plane around z axis 45°
	- rotate y, z plane around x axis 54.74°(arctan(√2))
	new_vector = Rx⋅Rz⋅vector
	Rx, Rz: rotation matrices
*/

void	multiply_vector_by_matrix(t_3d_vector *v, t_3d_matrix m)
{
	t_3d_vector	v0;

	v0 = *v;
	(*v).x = v0.x * m.i.x + v0.y * m.j.x + v0.z * m.k.x;
	(*v).y = v0.x * m.i.y + v0.y * m.j.y + v0.z * m.k.y;
	(*v).z = v0.x * m.i.z + v0.y * m.j.z + v0.z * m.k.z;
}

t_3d_matrix	get_rotation_matrix(double angle, char axis)
{
	if (axis == 'x')
		return ((t_3d_matrix){
			(t_3d_vector){1, 0, 0, 0},
			(t_3d_vector){0, cos(angle), sin(angle), 0},
			(t_3d_vector){0, -sin(angle), cos(angle), 0}
	});
	if (axis == 'y')
		return ((t_3d_matrix){
			(t_3d_vector){cos(angle), 0, -sin(angle), 0},
			(t_3d_vector){0, 1, 0, 0},
			(t_3d_vector){sin(angle), 0, cos(angle), 0}
	});
	if (axis == 'z')
		return ((t_3d_matrix){
			(t_3d_vector){cos(angle), sin(angle), 0, 0},
			(t_3d_vector){-sin(angle), cos(angle), 0, 0},
			(t_3d_vector){0, 0, 1, 0}
	});
	return ((t_3d_matrix){
		(t_3d_vector){1, 0, 0, 0},
		(t_3d_vector){0, 1, 0, 0},
		(t_3d_vector){0, 0, 1, 0}
	});
}

static double	degrees_to_radians(double degrees)
{
	return (degrees * M_PI / 180);
}

void	isometric(t_3d_vector *v)
{
	double		angle_z;
	double		angle_x;

	angle_z = degrees_to_radians(45);
	angle_x = atan(sqrt(2));
	multiply_vector_by_matrix(v, get_rotation_matrix(angle_z, 'z'));
	multiply_vector_by_matrix(v, get_rotation_matrix(angle_x, 'x'));
}

void	parallel(t_3d_vector *v)
{
	multiply_vector_by_matrix(v, get_rotation_matrix(0, 'x'));
	multiply_vector_by_matrix(v, get_rotation_matrix(0, 'y'));
	multiply_vector_by_matrix(v, get_rotation_matrix(0, 'z'));
}
