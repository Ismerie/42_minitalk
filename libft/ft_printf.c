/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:37:23 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/14 15:37:23 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (ft_strlen("(null)"));
	}
	else
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
}

static int	ft_size(int size, char c)
{
	if (c == 'c' || c == '%')
		size++;
	return (size);
}

static void	ft_check_arg(char c, va_list argptr, int *size)
{
	*size = ft_size(*size, c);
	if (c == 'c')
		ft_putchar_fd((char)va_arg(argptr, int), 1);
	else if (c == 's')
		*size += ft_putstr(va_arg(argptr, char *));
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(argptr, int), size);
	else if (c == 'x' || c == 'X' || c == 'u')
		ft_putnbr_base(va_arg(argptr, unsigned int), size, c);
	else if (c == 'p')
		ft_putnbr_long(va_arg(argptr, unsigned long), size);
	else
	{
		ft_putchar_fd(c, 1);
		*size = *size + 1;
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	argptr;
	int		size;

	i = 0;
	size = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			size++;
			i++;
		}
		else
		{
			ft_check_arg(str[i + 1], argptr, &size);
			i = i + 2;
		}
	}
	va_end(argptr);
	return (size);
}
