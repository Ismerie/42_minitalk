/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:49:02 by igeorge           #+#    #+#             */
/*   Updated: 2022/02/18 13:03:34 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft__gnl_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft__gnl_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] == (char) c)
			return (1);
	}
	if (str[i] == c)
		return (1);
	return (0);
}

char	*ft_gnl_strjoin(char *save, char *buf)
{
	int		i;
	int		j;
	char	*new_save;

	if (!save)
	{
		save = malloc(sizeof(char) * 1);
		if (!save)
			return (ft_free(buf, NULL));
		save[0] = '\0';
	}
	new_save = malloc(sizeof(char) * ((ft_gnl_strlen(save) + ft_gnl_strlen(buf)) + 1));
	if (!new_save)
		return (ft_free(buf, save));
	i = -1;
	j = 0;
	while (save[++i] != '\0')
		new_save[i] = save[i];
	while (buf[j] != '\0')
		new_save[i++] = buf[j++];
	new_save[ft_gnl_strlen(save) + ft_gnl_strlen(buf)] = '\0';
	free(save);
	return (new_save);
}

char	*ft_free(char *str, char *str2)
{
	if (str)
		free(str);
	if (str2)
		free(str2);
	return (NULL);
}
