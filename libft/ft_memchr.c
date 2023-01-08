/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:57:49 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/06 15:17:32 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			*tab;
	unsigned char			a;

	if (!s && n && c)
		return (NULL);
	a = (unsigned char) c;
	tab = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (tab[i] == a)
			return ((void *)(tab + i));
		i++;
	}
	return (NULL);
}
