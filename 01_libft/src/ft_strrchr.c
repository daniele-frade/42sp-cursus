/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielefrade <danielefrade@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:48:26 by dfrade            #+#    #+#             */
/*   Updated: 2023/08/01 14:50:50 by danielefrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*last_occ;

	len = ft_strlen(s);
	last_occ = (char *)(s + len);
	while (*last_occ != (unsigned char)c && len)
	{
		last_occ--;
		len--;
	}
	if (*last_occ == (unsigned char)c)
		return (last_occ);
	return (0);
}
