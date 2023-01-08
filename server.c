/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:41:14 by igeorge           #+#    #+#             */
/*   Updated: 2022/03/29 15:41:14 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <libft.h>

static void	action(int sig, siginfo_t *info, void *context)
{
	static char		binary = 0;
	static int		i_bit = 0;

	(void)context;
	if (sig == SIGUSR1)
		binary |= 1;
	i_bit++;
	if (i_bit < 8)
		binary = binary << 1;
	else
	{
		if (binary)
		{
			ft_putchar_fd(binary, 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR2);
		}
		binary = 0;
		i_bit = 0;
	}
}


int	main(void)
{
	struct	sigaction	s_sigaction;
	
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while(1)
		pause();
	return (0);
}
