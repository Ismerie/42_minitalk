/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:41:28 by igeorge           #+#    #+#             */
/*   Updated: 2022/03/29 15:41:28 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <libft.h>

static void signal_receive(int sig)
{
	static int	signal = 0;
	
	if (sig == SIGUSR1)
		signal++;
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("Byte(s) sent : ", 1);
		ft_putnbr_fd(signal, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}

}

static void	send_bit(char *str, int pid)
{
	int	i_str;
	int	i_bit;
	int	size;

	i_str = 0;
	size = ft_strlen(str) + 1;
	while (i_str < size)
	{
		i_bit = 7;
		while (i_bit >= 0)
		{
			if ((str[i_str] >> i_bit) & 1)
				kill(pid, SIGUSR1);
			else 
				kill(pid, SIGUSR2);
			i_bit--;
			usleep(20);
		}
		i_str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	signal(SIGUSR1, signal_receive);
	signal(SIGUSR2, signal_receive);
	send_bit(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
