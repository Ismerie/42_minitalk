/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:53:07 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/06 15:34:21 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	char	*str1;
	char	*str2;
	int		j;

	str1 = (char *) s1;
	str2 = (char *) s2;
	i = 0;
	if (!*str2)
		return (str1);
	while (i < len && s1[i] != 0)
	{
		j = 0;
		while (str1[i + j] && str2[j] && i + j < len && str1[i + j] == str2[j])
		{
			j++;
			if (str2[j] == 0)
				return (str1 + i);
		}
		i++;
	}
	return (0);
}
