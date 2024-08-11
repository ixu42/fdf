/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:48:08 by ixu               #+#    #+#             */
/*   Updated: 2024/08/11 15:09:47 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate(t_fdf *data, t_3d_vector *v)
{
	double	angle_x;
	double	angle_y;

	angle_x = data->angle_x;
	angle_y = data->angle_y;
	multiply_vector_by_matrix(v, get_rotation_matrix(angle_x, 'x'));
	multiply_vector_by_matrix(v, get_rotation_matrix(angle_y, 'y'));
}

/*
	set coordinates and colors:
	1. scale up the x, y coordinates
	2. 3D to 2D projection
	3. shift the position of object to center of the image
*/

void	transform(t_fdf *data, t_3d_vector *v1, t_3d_vector *v2)
{
	(*v1).x *= data->scale;
	(*v1).y *= data->scale;
	(*v1).z *= data->scale * data->z_scale;
	(*v2).x *= data->scale;
	(*v2).y *= data->scale;
	(*v2).z *= data->scale * data->z_scale;
	if (data->mode == 'i')
	{
		isometric(v1);
		isometric(v2);
	}
	if (data->mode == 'p')
	{
		parallel(v1);
		parallel(v2);
	}
	rotate(data, v1);
	rotate(data, v2);
	get_coords_to_centralize(data);
	(*v1).x += data->x_to_center + data->move_x;
	(*v1).y += data->y_to_center + data->move_y;
	(*v2).x += data->x_to_center + data->move_x;
	(*v2).y += data->y_to_center + data->move_y;
}
