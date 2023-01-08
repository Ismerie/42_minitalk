/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:55:35 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/07 12:55:35 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_number(unsigned int n)
{
	int	size;

	size = 0;
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

static void	ft_put_result(unsigned int nbr, char *tab, int negative, int i)
{
	if (nbr == 0)
		tab[0] = 48;
	while (nbr != 0)
	{
		tab[i - 1 + negative] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int				i;
	char			*tab;
	unsigned int	nbr;
	int				negative;

	negative = 0;
	if (n < 0)
	{
		negative++;
		n = -n;
	}
	nbr = n;
	i = ft_size_number(nbr);
	tab = malloc((i + 1 + negative) * sizeof(char));
	if (!tab)
		return (0);
	tab[i + negative] = '\0';
	ft_put_result(nbr, tab, negative, i);
	if (negative == 1)
		tab[0] = '-';
	return (tab);
}
