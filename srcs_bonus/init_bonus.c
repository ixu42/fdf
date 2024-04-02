/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:50:07 by ixu               #+#    #+#             */
/*   Updated: 2024/01/28 22:35:32 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

// get the minimum x, y and maximum x, y of the projected object

static void	get_min_max_coords(t_fdf **data)
{
	t_3d_vector	v1;
	t_3d_vector	v2;

	(*data)->min.x = DBL_MAX;
	(*data)->min.y = DBL_MAX;
	(*data)->max.x = -DBL_MAX;
	(*data)->max.y = -DBL_MAX;
	v1.y = -1;
	while (++v1.y < (*data)->depth)
	{
		v1.x = -1;
		while (++v1.x < (*data)->width)
		{
			v1.z = (*data)->z[(int)v1.y][(int)v1.x];
			v2 = v1;
			isometric(&v2);
			(*data)->min.x = fmin((*data)->min.x, v2.x);
			(*data)->min.y = fmin((*data)->min.y, v2.y);
			(*data)->max.x = fmax((*data)->max.x, v2.x);
			(*data)->max.y = fmax((*data)->max.y, v2.y);
		}
	}
}

/* 
	x_to_center, y_to_center:
		how much x, y coordinates should be moved so that
		the object appears in the center of the image
*/

void	get_coords_to_centralize(t_fdf *data)
{
	double	width;
	double	depth;

	if (data->mode == 'i')
	{
		width = (data->max.x + data->min.x) * data->scale;
		depth = (data->max.y + data->min.y) * data->scale;
		data->x_to_center = (IMG_WIDTH - width) / 2;
		data->y_to_center = (IMG_HEIGHT - depth) / 2;
	}
	else if (data->mode == 'p')
	{
		width = data->width * data->scale;
		depth = data->depth * data->scale;
		data->x_to_center = (IMG_WIDTH - width) / 2;
		data->y_to_center = (IMG_HEIGHT - depth) / 2;
	}
}

void	data_init(t_fdf **data)
{
	double	width;
	double	depth;
	double	zoom_x;
	double	zoom_y;

	(*data)->speed = 10;
	(*data)->mode = 'i';
	(*data)->color_mode = 0;
	(*data)->z_scale = 1;
	(*data)->angle_x = 0;
	(*data)->angle_y = 0;
	(*data)->angle_z = 0;
	get_min_max_coords(data);
	width = (*data)->max.x - (*data)->min.x;
	depth = (*data)->max.y - (*data)->min.y;
	zoom_x = (double)(IMG_WIDTH * 0.7) / width;
	zoom_y = (double)(IMG_HEIGHT * 0.7) / depth;
	(*data)->scale = fmin(zoom_x, zoom_y);
	get_coords_to_centralize(*data);
	(*data)->move_x = 0;
	(*data)->move_y = 0;
}
