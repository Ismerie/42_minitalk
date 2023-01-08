/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:26:21 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/06 15:39:19 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	if (!s && c)
		return (NULL);
	a = (char) c;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == a)
			return ((char *)(s + i));
		else
			i++;
	}
	if (s[i] == a)
		return ((char *)(s + i));
	return (NULL);
}
