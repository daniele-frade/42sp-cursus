/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:40:41 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/11 14:49:27 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_so_long *so_long, void *img, int col, int line)
{
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, img,
		col * IMG_SIZE, line * IMG_SIZE);
}

int	print_map_on_screen(t_so_long *so_long)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (so_long->map[line] != NULL)
	{
		while (so_long->map[line][col] != '\0')
		{
			if (so_long->map[line][col] == '1')
				ft_put_image(so_long, so_long->wall, col, line);
			else if (so_long->map[line][col] == '0')
				ft_put_image(so_long, so_long->tile, col, line);
			else if (so_long->map[line][col] == 'P')
				ft_put_image(so_long, so_long->player, col, line);
			else if (so_long->map[line][col] == 'C')
				ft_put_image(so_long, so_long->collectible, col, line);
			else if (so_long->map[line][col] == 'E')
				ft_put_image(so_long, so_long->exit, col, line);
			col++;
		}
		col = 0;
		line++;
	}
	return (0);
}

void	move_player(t_so_long *so_long, int line_m, int col_m)
{
	if (so_long->map[so_long->line + line_m][so_long->col + col_m] == '0'
		|| so_long->map[so_long->line + line_m][so_long->col + col_m] == 'C')
	{
		so_long->map[so_long->line][so_long->col] = '0';
		so_long->map[so_long->line + line_m][so_long->col + col_m] = 'P';
		so_long->col = so_long->col + col_m;
		so_long->line = so_long->line + line_m;
		ft_printf("Steps: %d\n", ++so_long->steps);
	}
	else if (so_long->map[so_long->line + line_m][so_long->col + col_m] == 'E')
	{
		if (!map_contain_collectible(so_long))
		{
			ft_printf("Steps: %d\n", ++so_long->steps);
			end_mlx(so_long);
		}
	}
}

int	mlx_key_events(int key, t_so_long *so_long)
{
	if (key == 65307)
		end_mlx(so_long);
	else if (key == 65362 || key == 119)
		move_player(so_long, -1, 0);
	else if (key == 65364 || key == 115)
		move_player(so_long, 1, 0);
	else if (key == 65361 || key == 97)
		move_player(so_long, 0, -1);
	else if (key == 65363 || key == 100)
		move_player(so_long, 0, 1);
	return (1);
}

int	click_x_mlx(t_so_long *so_long)
{
	end_mlx(so_long);
	return (1);
}
