/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:14:24 by ixu               #+#    #+#             */
/*   Updated: 2024/04/02 15:42:06 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

static void	ft_hook(void *param)
{
	t_fdf	*data;

	data = param;
	translate_rotate_zoom(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_P))
		data->mode = 'p';
	else if (mlx_is_key_down(data->mlx, MLX_KEY_I))
		data->mode = 'i';
	else if (mlx_is_key_down(data->mlx, MLX_KEY_C))
		data->color_mode = 1;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		data_init(&data);
	draw_bg_color(data);
	draw(data);
}

// xdelta for detecting a mousewheel that goes along the X (e.g.: MX Master 3)

static void	my_scrollhook(double xdelta, double ydelta, void *param)
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

static void	win_img_init(t_fdf *data)
{
	data->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "fil de fer", true);
	if (data->mlx == NULL)
	{
		perror((char *)mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	data->image = mlx_new_image(data->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (data->image == NULL)
	{
		mlx_close_window(data->mlx);
		perror((char *)mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		perror((char *)mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	validate_args(argc, argv);
	data = malloc(sizeof(t_fdf));
	if (data == NULL)
		print_error(ERR_MALLOC);
	win_img_init(data);
	read_file(argv[1], &data);
	data_init(&data);
	draw_bg_color(data);
	draw(data);
	mlx_scroll_hook(data->mlx, my_scrollhook, data);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free_int_arr(data->z);
	free_uint_arr(data->colors);
	free(data);
	exit(EXIT_SUCCESS);
}
