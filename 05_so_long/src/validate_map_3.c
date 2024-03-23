/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:04:48 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/10 18:19:56 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(t_so_long *so_long)
{
	int	line;

	line = 0;
	while (so_long->map[line] != NULL)
		line++;
	return (line);
}

int	duplicate_map(t_so_long *so_long)
{
	int	count_lines;
	int	current_line;

	count_lines = count_line(so_long);
	so_long->map_copy = ft_calloc((count_lines + 1), sizeof(char *));
	if (so_long->map_copy == NULL)
		return (print_error("Unable to allocate memory for the map_copy.\n"));
	current_line = 0;
	while (count_lines > current_line)
	{
		so_long->map_copy[current_line] = ft_strdup(so_long->map[current_line]);
		if (so_long->map_copy[current_line] == NULL)
		{
			free_matrix(so_long->map_copy);
			return (print_error
				("Unable to allocate memory for the map_copy.\n"));
		}
		current_line++;
	}
	so_long->map_copy[current_line] = NULL;
	return (1);
}

void	map_player_position(t_so_long *so_long)
{
	so_long->line = 0;
	so_long->col = 0;
	while (so_long->map_copy[so_long->line] != NULL)
	{
		while (so_long->map_copy[so_long->line][so_long->col] != '\0')
		{
			if (so_long->map_copy[so_long->line][so_long->col] == 'P')
				return ;
			so_long->col++;
		}
		so_long->col = 0;
		so_long->line++;
	}
}

void	flood_fill(char **map_copy, int line, int col)
{
	if (map_copy[line][col] == '1' || map_copy[line][col] == 'F')
		return ;
	if (map_copy[line][col] == 'E')
	{
		map_copy[line][col] = 'F';
		return ;
	}
	map_copy[line][col] = 'F';
	flood_fill(map_copy, line + 1, col);
	flood_fill(map_copy, line, col + 1);
	flood_fill(map_copy, line - 1, col);
	flood_fill(map_copy, line, col - 1);
}

int	map_path_is_valid(t_so_long *so_long)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (so_long->map_copy[line] != NULL)
	{
		while (so_long->map_copy[line][col] != '\0')
		{
			if (so_long->map_copy[line][col] == 'C'
				|| so_long->map_copy[line][col] == 'E')
				return (0);
			col++;
		}
		col = 0;
		line++;
	}
	return (1);
}
