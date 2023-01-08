/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:43:17 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/06 15:25:20 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tab1;
	unsigned char	*tab2;

	if (!dest && !src)
		return (0);
	tab1 = (unsigned char *) src;
	tab2 = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		tab2[i] = tab1[i];
		i++;
	}
	return (dest);
}
