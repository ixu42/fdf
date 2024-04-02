/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:25:00 by ixu               #+#    #+#             */
/*   Updated: 2024/01/28 20:50:07 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// connecting two points with a line

static void	draw_line(t_3d_vector v1, t_3d_vector v2, t_fdf *data)
{
	double		x_steps;
	double		y_steps;
	double		max_steps;
	t_3d_vector	curr;

	transform(data, &v1, &v2);
	x_steps = v2.x - v1.x;
	y_steps = v2.y - v1.y;
	max_steps = fmax(fabs(x_steps), fabs(y_steps));
	x_steps = x_steps / max_steps;
	y_steps = y_steps / max_steps;
	curr.x = v1.x;
	curr.y = v1.y;
	while (((int)(v2.x - curr.x) || (int)(v2.y - curr.y))
		&& (curr.x >= 0 && curr.y >= 0
		&& curr.x <= IMG_WIDTH && curr.y <= IMG_HEIGHT))
	{
		curr.color = get_grad(v1, v2, curr);
		mlx_put_pixel(data->image, curr.x, curr.y, curr.color);
		curr.x = curr.x + x_steps;
		curr.y = curr.y + y_steps;
	}
}

static void	draw_lines(t_3d_vector v, t_fdf *data)
{
	t_3d_vector	next_v;

	if (v.x < data->width - 1)
	{
		next_v.x = v.x + 1;
		next_v.y = v.y;
		next_v.z = data->z[(int)next_v.y][(int)next_v.x];
		next_v.color = get_color(data, next_v);
		draw_line(v, next_v, data);
	}
	if (v.y < data->depth - 1)
	{
		next_v.x = v.x;
		next_v.y = v.y + 1;
		next_v.z = data->z[(int)next_v.y][(int)next_v.x];
		next_v.color = get_color(data, next_v);
		draw_line(v, next_v, data);
	}
}

void	draw(t_fdf *data)
{
	t_3d_vector	v1;

	v1.y = -1;
	while (++v1.y < data->depth)
	{
		v1.x = -1;
		while (++v1.x < data->width)
		{
			v1.z = data->z[(int)v1.y][(int)v1.x];
			v1.color = get_color(data, v1);
			draw_lines(v1, data);
		}
	}
}

// draw background color (black) on image

void	draw_bg_color(t_fdf *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (int)(data->image->height))
	{
		x = -1;
		while (++x < (int)(data->image->width))
			mlx_put_pixel(data->image, x, y, 0x000000ff);
	}
}
