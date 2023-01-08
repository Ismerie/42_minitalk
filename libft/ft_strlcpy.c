/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:30:29 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/13 17:35:33 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strl(const char *str)
{
	int	nbr;

	nbr = 0;
	while (str[nbr] > 0)
		nbr++;
	return (nbr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if ((!dest || !src) && !size)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{	
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strl(src));
}
