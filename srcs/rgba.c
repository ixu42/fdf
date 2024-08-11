/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:58:32 by ixu               #+#    #+#             */
/*   Updated: 2024/08/11 15:09:47 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_color	rgba_to_color(uint32_t rgba)
{
	t_color	color;

	color.r = (rgba >> 24) & 0xFF;
	color.g = (rgba >> 16) & 0xFF;
	color.b = (rgba >> 8) & 0xFF;
	color.a = rgba & 0xFF;
	return (color);
}

t_color	rgb_to_color(uint32_t rgb)
{
	t_color	color;

	color.r = (rgb >> 16) & 0xFF;
	color.g = (rgb >> 8) & 0xFF;
	color.b = rgb & 0xFF;
	color.a = 0xFF;
	return (color);
}

t_color	rg_to_color(uint32_t rg)
{
	t_color	color;

	color.r = (rg >> 8) & 0xFF;
	color.g = rg & 0xFF;
	color.b = 0x00;
	color.a = 0xFF;
	return (color);
}

t_color	r_to_color(uint32_t r)
{
	t_color	color;

	color.r = r & 0xFF;
	color.g = 0x00;
	color.b = 0x00;
	color.a = 0xFF;
	return (color);
}

uint32_t	get_rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
