/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:05:39 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/08 17:05:39 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	unsigned int	size;

	size = 0;
	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		size++;
		nb = -n;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		size++;
		nb %= 10;
	}
	ft_putchar_fd(nb + 48, fd);
}
