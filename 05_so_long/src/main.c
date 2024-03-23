/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:40:31 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/11 13:04:49 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_1(char *file_name, t_so_long *so_long)
{
	if (!map_is_ber_file(file_name))
		return (print_error("Your map doesn't match the requirements.\n"));
	if (!read_map(file_name, so_long))
		return (0);
	if (!create_map(file_name, so_long))
		return (0);
	remove_line_feed_in_map(so_long->map);
	if (!map_contain_valid_char(so_long))
		return (print_error("Your map doesn't match the requirements.\n"));
	if (!map_is_rectangle(so_long))
		return (print_error("Your map doesn't match the requirements.\n"));
	if (!map_is_closed_by_walls(so_long))
		return (print_error("Your map doesn't match the requirements.\n"));
	if (!map_contain_exit(so_long))
		return (print_error("Your map doesn't match the requirements.\n"));
	if (!map_contain_collectible(so_long))
		return (print_error("Your map doesn't match the requirements.\n"));
	if (!map_contain_player(so_long))
		return (print_error("Your map doesn't match the requirements.\n"));
	return (1);
}

int	check_map_2(t_so_long *so_long)
{
	if (!duplicate_map(so_long))
	{
		free_matrix(so_long->map);
		return (0);
	}
	map_player_position(so_long);
	flood_fill(so_long->map_copy, so_long->line, so_long->col);
	if (!map_path_is_valid(so_long))
		return (print_error("Your map doesn't match the requirements.\n"));
	return (1);
}

void	load_images(t_so_long *so_long)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	so_long->tile = mlx_xpm_file_to_image(so_long->mlx, "./images/tile.xpm",
			&x, &y);
	if (so_long->tile == NULL)
		end_mlx(so_long);
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
			"./images/wall.xpm", &x, &y);
	if (so_long->wall == NULL)
		end_mlx(so_long);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx,
			"./images/player.xpm", &x, &y);
	if (so_long->player == NULL)
		end_mlx(so_long);
	so_long->collectible = mlx_xpm_file_to_image(so_long->mlx,
			"./images/collectible.xpm", &x, &y);
	if (so_long->collectible == NULL)
		end_mlx(so_long);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
			"./images/exit.xpm", &x, &y);
	if (so_long->exit == NULL)
		end_mlx(so_long);
}

void	display_map(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	if (so_long->mlx == NULL)
		end_mlx(so_long);
	so_long->mlx_win = mlx_new_window(so_long->mlx,
			ft_strlen(so_long->map[0]) * IMG_SIZE,
			count_line(so_long) * IMG_SIZE, "So Long");
	if (so_long->mlx_win == NULL)
		end_mlx(so_long);
	load_images(so_long);
	mlx_loop_hook(so_long->mlx, print_map_on_screen, so_long);
	mlx_hook(so_long->mlx_win, KeyPress, KeyPressMask, mlx_key_events, so_long);
	mlx_hook(so_long->mlx_win, DestroyNotify,
		StructureNotifyMask, click_x_mlx, so_long);
	mlx_loop(so_long->mlx);
}

int	main(int argc, char **argv)
{
	t_so_long	so_long;

	ft_bzero(&so_long, sizeof(t_so_long));
	if (argc == 2)
	{
		if (check_map_1(argv[1], &so_long) && (check_map_2(&so_long)))
			display_map(&so_long);
		else
		{
			free_matrix(so_long.map);
			free_matrix(so_long.map_copy);
		}
	}
	else
		return (print_error("Invalid number of arguments.\n"));
}
