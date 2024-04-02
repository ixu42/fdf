/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:44:14 by ixu               #+#    #+#             */
/*   Updated: 2024/01/28 20:38:17 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

uint32_t	get_color(t_fdf *data, t_3d_vector v)
{
	uint32_t	color;

	if (data->color_mode && v.z > 0)
		color = 0x67f2d1ff;
	else if (data->color_mode && v.z == 0)
		color = 0x3d4c99ff;
	else
		color = data->colors[(int)v.y][(int)v.x];
	return (color);
}

uint32_t	parse_color(char *str)
{
	t_color	color;

	if (str != NULL && (str + 2) != NULL)
	{
		if (ft_strlen(str + 2) == 8)
			color = rgba_to_color(ft_atoi_base(str + 2, 16));
		else if (ft_strlen(str + 2) == 6)
			color = rgb_to_color(ft_atoi_base(str + 2, 16));
		else if (ft_strlen(str + 2) == 4)
			color = rg_to_color(ft_atoi_base(str + 2, 16));
		else if (ft_strlen(str + 2) == 2)
			color = r_to_color(ft_atoi_base(str + 2, 16));
		return (get_rgba(color.r, color.g, color.b, color.a));
	}
	return (get_rgba(0xFF, 0xFF, 0xFF, 0xFF));
}
