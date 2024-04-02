/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:14:01 by ixu               #+#    #+#             */
/*   Updated: 2024/01/28 22:19:28 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	print_error(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

void	error_free_data(char *err_msg, t_fdf *data)
{
	perror(err_msg);
	free(data);
	data = NULL;
	exit(EXIT_FAILURE);
}

void	error_free_data_int_arr(char *err_msg, t_fdf *data)
{
	perror(err_msg);
	free_int_arr(data->z);
	free(data);
	data = NULL;
	exit(EXIT_FAILURE);
}

void	error_free_data_int_n_uint_arrs(char *err_msg, t_fdf *data)
{
	perror(err_msg);
	free_int_arr(data->z);
	free_uint_arr(data->colors);
	free(data);
	data = NULL;
	exit(EXIT_FAILURE);
}

void	validate_args(int argc, char **argv)
{
	char	*filename;
	char	*extension;

	if (argc != 2)
	{
		if (ft_putendl_fd(ERR_ARGS, STDERR_FILENO) == -1)
			print_error(ERR_WRITE);
		if (ft_putendl_fd(EX_ARGS, STDOUT_FILENO) == -1)
			print_error(ERR_WRITE);
		exit(EXIT_FAILURE);
	}
	filename = ft_strdup(argv[1]);
	extension = ft_strdup(".fdf");
	if (ft_strcmp(filename + ft_strlen(filename) - 4, extension) != 0)
	{
		free(filename);
		free(extension);
		if (ft_putendl_fd(ERR_ARGS, STDERR_FILENO) == -1)
			print_error(ERR_WRITE);
		if (ft_putendl_fd(EX_ARGS, STDOUT_FILENO) == -1)
			print_error(ERR_WRITE);
		exit(EXIT_FAILURE);
	}
	free(filename);
	free(extension);
}
