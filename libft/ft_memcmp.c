/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:22:38 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/06 15:22:06 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tab1;
	unsigned char	*tab2;

	tab1 = (unsigned char *) s1;
	tab2 = (unsigned char *) s2;
	i = 0;
	while (n > 0)
	{
		if (tab1[i] != tab2[i])
			return (tab1[i] - tab2[i]);
		i++;
		n--;
	}
	return (0);
}
