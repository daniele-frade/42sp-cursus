/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_create_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:39:43 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/10 19:39:20 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(char *file_name, t_so_long *so_long)
{
	int		file_open;
	char	*line_read;

	file_open = open(file_name, O_RDONLY);
	if (file_open == -1)
		return (print_error("Your file couldn't be opened.\n"));
	line_read = get_next_line(file_open);
	if (line_read == NULL)
		return (print_error("Your file is empty.\n"));
	so_long->count_line = 1;
	free(line_read);
	while (line_read != NULL)
	{
		line_read = get_next_line(file_open);
		if (line_read != NULL)
		{
			so_long->count_line++;
			free(line_read);
		}
	}
	close(file_open);
	return (1);
}

int	create_map(char *file_name, t_so_long *so_long)
{
	int		current_line;
	int		file_open;
	char	*line_read;

	so_long->map = ft_calloc((so_long->count_line + 1), sizeof(char *));
	if (so_long->map == NULL)
		return (print_error("Unable to allocate memory for the map.\n"));
	file_open = open(file_name, O_RDONLY);
	if (file_open == -1)
		return (print_error("Your file couldn't be opened.\n"));
	current_line = 0;
	while (so_long->count_line > current_line)
	{
		line_read = get_next_line(file_open);
		if (line_read == NULL)
		{
			free_matrix(so_long->map);
			return (print_error("The line was not read successfully.\n"));
		}
		so_long->map[current_line++] = line_read;
	}
	so_long->map[current_line] = NULL;
	return (1);
}

void	remove_line_feed_in_map(char **map)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (map[line] != NULL)
	{
		while (map[line][col] != '\0')
		{
			if (map[line][col] == '\n')
			{
				map[line][col] = '\0';
			}
			col++;
		}
		col = 0;
		line++;
	}
}
