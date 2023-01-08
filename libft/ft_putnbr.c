/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:45:34 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/19 17:40:07 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, int *size)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		*size = *size + 1;
		nb = -n;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, size);
		nb %= 10;
	}
	*size = *size + 1;
	ft_putchar_fd(nb + 48, 1);
}

void	ft_putnbr_base(unsigned int nbr, int *size, char c)
{
	char	*base;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789";
	if (nbr >= ft_strlen(base))
	{
		ft_putnbr_base(nbr / ft_strlen(base), size, c);
		nbr %= ft_strlen(base);
	}
	*size = *size + 1;
	ft_putchar_fd(base[nbr], 1);
}

void	ft_putnbr_long_base(unsigned long nbr, int *size)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putnbr_long_base(nbr / 16, size);
		nbr %= 16;
	}
	*size = *size + 1;
	ft_putchar_fd(base[nbr], 1);
}

void	ft_putnbr_long(unsigned long nbr, int *size)
{
	ft_putstr_fd("0x", 1);
	*size = *size + 2;
	ft_putnbr_long_base(nbr, size);
}
