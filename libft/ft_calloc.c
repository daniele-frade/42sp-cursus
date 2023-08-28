/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:12:29 by dfrade            #+#    #+#             */
/*   Updated: 2023/08/03 10:09:25 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
