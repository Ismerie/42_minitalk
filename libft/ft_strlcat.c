/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:12:15 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/10 20:22:31 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != 0 && i < dstsize)
		i++;
	if (i == dstsize)
		return (dstsize + ft_strlen(src));
	while (src[j] != 0 && j < dstsize - i - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (i + ft_strlen(src));
}
