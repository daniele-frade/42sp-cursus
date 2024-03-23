/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:25:15 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/09 20:31:10 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_contain_collectible(t_so_long *so_long)
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
			if (so_long->map[line][col] == 'C')
				i++;
			col++;
		}
		col = 0;
		line++;
	}
	if (i < 1)
		return (0);
	return (1);
}

int	map_contain_player(t_so_long *so_long)
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
			if (so_long->map[line][col] == 'P')
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
