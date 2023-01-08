/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:51:10 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/06 15:41:04 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	a = (char) c;
	i = 0;
	while (s[i] != 0)
		i++;
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
