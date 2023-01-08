/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:38:53 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/13 18:57:22 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	tab = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (NULL);
	while (s1[i] != 0)
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		tab[j++] = s2[i++];
	tab[j] = 0;
	return (tab);
}
