/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:23:04 by ixu               #+#    #+#             */
/*   Updated: 2024/08/11 17:25:37 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// xdelta for detecting a mousewheel that goes along the X (e.g.: MX Master 3)

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf	*data;

	data = param;
	if (ydelta > 0)
		data->scale *= 1.02;
	else if (ydelta < 0)
		data->scale *= 0.98;
	if (xdelta < 0)
		data->z_scale -= 0.03;
	else if (xdelta > 0)
		data->z_scale += 0.03;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*data;

	data = (t_fdf *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
	{
		if (data->color_mode < 2)
			data->color_mode++;
		else
			data->color_mode = 0;
	}
	else if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		data->mode = 'p';
	else if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		data->mode = 'i';
	else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		data_init(&data);
}

static void	translate_rotate_zoom(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->move_y -= data->speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->move_x += data->speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->move_y += data->speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->move_x -= data->speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->angle_x += 0.02;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->angle_y += 0.02;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->angle_x -= 0.02;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->angle_y -= 0.02;
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_SUBTRACT))
		data->scale *= 0.99;
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_ADD))
		data->scale *= 1.01;
	if (mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->z_scale -= 0.03;
	if (mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->z_scale += 0.03;
}

void	ft_hook(void *param)
{
	t_fdf	*data;

	data = param;
	translate_rotate_zoom(data);
	draw_bg_color(data);
	draw(data);
}
