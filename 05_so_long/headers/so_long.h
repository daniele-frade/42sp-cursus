/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:26:12 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/11 11:53:04 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"

# define IMG_SIZE 62

typedef struct s_long
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**map_copy;
	int		line;
	int		col;
	int		steps;
	int		count_line;
	void	*tile;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_so_long;

// create map
int		read_map(char *file_name, t_so_long *so_long);
int		create_map(char *file_name, t_so_long *so_long);
void	remove_line_feed_in_map(char **map);

// validate map
int		map_is_ber_file(char *file_name);
int		map_contain_valid_char(t_so_long *so_long);
int		map_is_rectangle(t_so_long *so_long);
int		map_is_closed_by_walls(t_so_long *so_long);
int		map_contain_exit(t_so_long *so_long);
int		map_contain_collectible(t_so_long *so_long);
int		map_contain_player(t_so_long *so_long);
int		duplicate_map(t_so_long *so_long);
void	map_player_position(t_so_long *so_long);
void	flood_fill(char **map_copy, int line, int col);
int		map_path_is_valid(t_so_long *so_long);

// display map with mlx
int		print_map_on_screen(t_so_long *so_long);
void	move_player(t_so_long *so_long, int line_mov, int col_mov);
int		mlx_key_events(int key, t_so_long *so_long);
int		click_x_mlx(t_so_long *so_long);

// utils and errors
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		count_line(t_so_long *so_long);
int		print_error(char *error_msg);
void	free_matrix(char **matrix);
void	end_mlx(t_so_long *so_long);

#endif