/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:38:43 by Degef             #+#    #+#             */
/*   Updated: 2023/02/17 16:12:03 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_header.h"

static void	handle_binary_to_str(int sig, siginfo_t *info, void *ptr)
{
	static char	c;
	static int	num_of_bits;

	(void) ptr;
	(void) info;
	if (sig == SIGUSR1)
		c |= 1;
	if (sig == SIGUSR2)
		c |= 0;
	num_of_bits++;
	if (num_of_bits == 8)
	{
		write(1, &c, 1);
		num_of_bits = 0;
		c = 0;
	}
	c <<= 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("MUST HAVE 1 ARGUMENT ONLY!\n", 1);
		exit(EXIT_FAILURE);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_binary_to_str;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("Server PID:  ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		sleep(1);
	return (0);
}
