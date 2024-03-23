/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:41:20 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/10 14:43:35 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_ber_file(char *file_name)
{
	if (ft_strlen(file_name) < 5)
		return (0);
	if (file_name[ft_strlen(file_name) - 4] != '.')
		return (0);
	if (file_name[ft_strlen(file_name) - 3] != 'b')
		return (0);
	if (file_name[ft_strlen(file_name) - 2] != 'e')
		return (0);
	if (file_name[ft_strlen(file_name) - 1] != 'r')
		return (0);
	return (1);
}

int	map_contain_valid_char(t_so_long *so_long)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (so_long->map[line] != NULL)
	{
		while (so_long->map[line][col] != '\0')
		{
			if (so_long->map[line][col] != '0'
				&& so_long->map[line][col] != '1'
				&& so_long->map[line][col] != 'C'
				&& so_long->map[line][col] != 'E'
				&& so_long->map[line][col] != 'P')
				return (0);
			col++;
		}
		col = 0;
		line++;
	}
	return (1);
}

int	map_is_rectangle(t_so_long *so_long)
{
	int	line;
	int	col;
	int	first_line_size;

	line = 0;
	col = 0;
	first_line_size = ft_strlen(so_long->map[line]);
	while (so_long->map[line] != NULL)
	{
		col = ft_strlen(so_long->map[line]);
		if (first_line_size != col)
			return (0);
		line++;
	}
	return (1);
}

int	map_is_closed_by_walls(t_so_long *so_long)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (so_long->map[line] != NULL)
	{
		while (so_long->map[line][col] != '\0')
		{
			if (line == 0 && so_long->map[line][col] != '1')
				return (0);
			if (so_long->map[line + 1] == NULL
				&& so_long->map[line][col] != '1')
				return (0);
			if (col == 0 && so_long->map[line][col] != '1')
				return (0);
			if (so_long->map[line][col + 1] == '\0'
				&& so_long->map[line][col] != '1')
				return (0);
			col++;
		}
		col = 0;
		line++;
	}
	return (1);
}

int	map_contain_exit(t_so_long *so_long)
{
	int	line;
	int	col;
	int	i;

	line = 0;
	col = 0;
	i = 0;
	while (so_long->map[line] != NULL)
	{
		while (so_long->map[line][col] != '\0')
		{
			if (so_long->map[line][col] == 'E')
				i++;
			col++;
		}
		col = 0;
		line++;
	}
	if (i != 1)
		return (0);
	return (1);
}
