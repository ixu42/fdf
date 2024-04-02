/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:37:31 by ixu               #+#    #+#             */
/*   Updated: 2024/01/28 20:38:02 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// get position of current point with pythagoras' theorem

static double	get_pos(t_3d_vector start, t_3d_vector end, t_3d_vector curr)
{
	double	diag_full;
	double	diag_first_part;

	diag_full = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	diag_first_part = sqrt(pow(curr.x - start.x, 2) + pow(curr.y - start.y, 2));
	if (diag_full)
		return (diag_first_part / diag_full);
	return (1);
}

static uint32_t	get_curr_color(uint32_t color1, uint32_t color2, double pos)
{
	t_color	start;
	t_color	end;
	t_color	color;

	start = rgba_to_color(color1);
	end = rgba_to_color(color2);
	color.r = round(start.r * (1 - pos) + end.r * pos);
	color.g = round(start.g * (1 - pos) + end.g * pos);
	color.b = round(start.b * (1 - pos) + end.b * pos);
	color.a = round(start.a * (1 - pos) + end.a * pos);
	return (get_rgba(color.r, color.g, color.b, color.a));
}

uint32_t	gradient(t_3d_vector start, t_3d_vector end, t_3d_vector curr)
{
	double		pos;
	uint32_t	curr_color;

	pos = get_pos(start, end, curr);
	curr_color = get_curr_color(start.color, end.color, pos);
	return (curr_color);
}

uint32_t	get_grad(t_3d_vector v1, t_3d_vector v2, t_3d_vector curr)
{
	uint32_t	color;

	if (curr.x == v1.x)
		color = v1.color;
	else if (curr.x == v2.x)
		color = v2.color;
	else
		color = gradient(v1, v2, curr);
	return (color);
}
