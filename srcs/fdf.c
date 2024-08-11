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
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free_int_arr(data->z);
	free_uint_arr(data->colors);
	free(data);
	exit(EXIT_SUCCESS);
}
