/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:15:17 by ixu               #+#    #+#             */
/*   Updated: 2024/08/11 15:08:36 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <float.h>

# define WIN_WIDTH 1600
# define WIN_HEIGHT 900
# define IMG_WIDTH 1600
# define IMG_HEIGHT 900

# define ERR_WRITE "write error"
# define ERR_MALLOC "malloc error"
# define ERR_ARGS "error: invalid arguments"
# define EX_ARGS "usage: ./fdf map.fdf"

// color scheme
# define BLACK 0x000000ff
# define WHITE 0xffffffff
# define BLUE 0x3d4c99ff
# define CYAN 0x67f2d1ff
# define RED 0x3D0A0Aff
# define YELLOW 0xF5B100ff

typedef struct s_color
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;
}	t_color;

typedef struct s_3d_vector
{
	double		x;
	double		y;
	double		z;
	uint32_t	color;
}	t_3d_vector;

typedef struct s_3d_matrix
{
	t_3d_vector	i;
	t_3d_vector	j;
	t_3d_vector	k;
}	t_3d_matrix;

typedef struct s_fdf
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	int				width;
	int				depth;
	int				**z;
	uint32_t		**colors;
	double			scale;
	double			z_scale;
	double			speed;
	double			move_x;
	double			move_y;
	double			x_to_center;
	double			y_to_center;
	char			mode;
	int				color_mode;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	t_3d_vector		min;
	t_3d_vector		max;
}	t_fdf;

// reading map from .fdf file to struct
void		read_file(char *filename, t_fdf **data);

// handling colors
t_color		rgba_to_color(uint32_t rgba);
t_color		rgb_to_color(uint32_t rgb);
t_color		rg_to_color(uint32_t rg);
t_color		r_to_color(uint32_t r);
uint32_t	get_rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
uint32_t	parse_color(char *str);
uint32_t	get_color(t_fdf *data, t_3d_vector v);
uint32_t	gradient(t_3d_vector start, t_3d_vector end, t_3d_vector current);
uint32_t	get_grad(t_3d_vector v1, t_3d_vector v2, t_3d_vector curr);

// initializing data
void		get_coords_to_centralize(t_fdf *data);
void		data_init(t_fdf **data);

// funcs for freeing
void		free_arr(char **arr);
void		free_int_arr(int **arr);
void		free_uint_arr(uint32_t **arr);

// error handling
void		print_error(char *err_msg);
void		error_free_data(char *err_msg, t_fdf *data);
void		error_free_data_int_arr(char *err_msg, t_fdf *data);
void		error_free_data_int_n_uint_arrs(char *err_msg, t_fdf *data);
void		validate_args(int argc, char **argv);

// projection and transformation
void		multiply_vector_by_matrix(t_3d_vector *v, t_3d_matrix m);
t_3d_matrix	get_rotation_matrix(double angle, char axis);
void		isometric(t_3d_vector *v);
void		parallel(t_3d_vector *v);
void		rotate(t_fdf *data, t_3d_vector *v);
void		transform(t_fdf *data, t_3d_vector *v1, t_3d_vector *v2);

// putting pixels to image and drawing lines
void		draw(t_fdf *data);
void		draw_bg_color(t_fdf *data);

#endif