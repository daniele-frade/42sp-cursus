/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_erros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:45:35 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/11 13:09:03 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	n_bytes;

	if (!nmemb || !size)
		return (malloc(0));
	n_bytes = nmemb * size;
	if (n_bytes / nmemb != size)
		return (NULL);
	ptr = malloc(n_bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n_bytes);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix == NULL)
		return ;
	while (matrix[i] != NULL)
		free(matrix[i++]);
	free(matrix);
}

int	print_error(char *error_msg)
{
	ft_printf("Error\n");
	ft_printf("%s", error_msg);
	return (0);
}

void	end_mlx(t_so_long *so_long)
{
	if (so_long->tile)
		mlx_destroy_image(so_long->mlx, so_long->tile);
	if (so_long->wall)
		mlx_destroy_image(so_long->mlx, so_long->wall);
	if (so_long->exit)
		mlx_destroy_image(so_long->mlx, so_long->exit);
	if (so_long->player)
		mlx_destroy_image(so_long->mlx, so_long->player);
	if (so_long->collectible)
		mlx_destroy_image(so_long->mlx, so_long->collectible);
	if (so_long->mlx_win)
		mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	if (so_long->mlx)
	{
		mlx_destroy_display(so_long->mlx);
		free(so_long->mlx);
	}
	free_matrix(so_long->map);
	free_matrix(so_long->map_copy);
	exit(0);
}
