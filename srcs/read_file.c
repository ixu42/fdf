/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:57:57 by ixu               #+#    #+#             */
/*   Updated: 2024/08/11 15:09:47 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	get_width(char *filename, t_fdf *data)
{
	char	*line;
	char	**items;
	int		width;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_free_data(filename, data);
	line = get_next_line(fd);
	items = ft_split(line, ' ');
	width = 0;
	while (items[width] != NULL && *(items[width]) != '\n')
		width++;
	free(line);
	free_arr(items);
	if (close(fd) == -1)
		error_free_data(filename, data);
	return (width);
}

static int	get_depth(char *filename, t_fdf *data)
{
	char	*line;
	int		depth;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_free_data(filename, data);
	line = get_next_line(fd);
	depth = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		depth++;
	}
	if (close(fd) == -1)
		error_free_data(filename, data);
	return (depth);
}

static void	parse_line(int fd, t_fdf **data, int y)
{
	char	*line;
	char	**items;
	char	**alt_color;
	char	*tmp;
	int		x;

	line = get_next_line(fd);
	items = ft_split(line, ' ');
	free(line);
	x = -1;
	while (++x < (*data)->width)
	{
		(*data)->z[y][x] = ft_atoi(items[x]);
		alt_color = ft_split(items[x], ',');
		if (alt_color[1] != NULL && ft_strchr(alt_color[1], '\n'))
		{
			tmp = alt_color[1];
			alt_color[1] = ft_strtrim(tmp, "\n\r");
			free(tmp);
		}
		(*data)->colors[y][x] = parse_color(alt_color[1]);
		free_arr(alt_color);
	}
	free_arr(items);
}

static void	fill_arrs(int fd, t_fdf **data)
{
	int		y;

	y = -1;
	while (++y < (*data)->depth)
	{
		(*data)->z[y] = malloc(sizeof(int) * (*data)->width);
		if ((*data)->z[y] == NULL)
		{
			free((*data)->colors);
			error_free_data_int_arr(ERR_MALLOC, *data);
		}
		(*data)->colors[y] = malloc(sizeof(uint32_t) * (*data)->width);
		if ((*data)->colors[y] == NULL)
			error_free_data_int_n_uint_arrs(ERR_MALLOC, *data);
		parse_line(fd, data, y);
	}
	(*data)->z[y] = NULL;
	(*data)->colors[y] = NULL;
}

void	read_file(char *filename, t_fdf **data)
{
	int		fd;

	(*data)->width = get_width(filename, *data);
	(*data)->depth = get_depth(filename, *data);
	(*data)->z = malloc(sizeof(int *) * (*data)->depth + 1);
	if ((*data)->z == NULL)
		error_free_data(ERR_MALLOC, *data);
	(*data)->colors = malloc(sizeof(uint32_t *) * (*data)->depth + 1);
	if ((*data)->colors == NULL)
	{
		free((*data)->z);
		error_free_data(ERR_MALLOC, *data);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free((*data)->z);
		free((*data)->colors);
		error_free_data(filename, *data);
	}
	fill_arrs(fd, data);
	if (close(fd) == -1)
		error_free_data_int_n_uint_arrs(filename, *data);
}
