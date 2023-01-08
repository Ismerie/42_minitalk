/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:26:29 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/10 20:22:59 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tab;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		tab = malloc(sizeof(char));
	else if (len > ft_strlen(s) - start)
		tab = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		tab = malloc((len + 1) * sizeof(char));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (j < len && s[i])
	{
		if (i >= (size_t)start)
			tab[j++] = *(s + i);
		i++;
	}
	tab[j] = '\0';
	return (tab);
}
