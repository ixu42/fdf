/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:48:08 by ixu               #+#    #+#             */
/*   Updated: 2024/02/02 11:49:30 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
	isometric(v1);
	isometric(v2);
	get_coords_to_centralize(data);
	(*v1).x += data->x_to_center;
	(*v1).y += data->y_to_center;
	(*v2).x += data->x_to_center;
	(*v2).y += data->y_to_center;
}
