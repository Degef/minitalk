/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:01:33 by Degef             #+#    #+#             */
/*   Updated: 2023/02/17 16:10:46 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

int	g_str_len;

static void	ft_str_to_binary(int pid, char *str)
{
	int	index;
	int	shift_len;

	index = 0;
	while (str[index])
	{
		shift_len = 7;
		while (shift_len >= 0)
		{
			if ((str[index] & (1 << shift_len)) > 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift_len--;
			usleep(100);
		}
		index++;
	}
}

static void	check_args(int pid, char *str)
{
	if (pid < MIN_PID || pid > MAX_PID)
	{
		ft_putstr_fd("Error! Wrong Process ID", 1);
		exit(EXIT_FAILURE);
	}
	if (!*str)
	{
		ft_putstr_fd("Error! No text to display", 1);
		exit(EXIT_FAILURE);
	}
}

static void	message(int sig, siginfo_t *info, void *ptr)
{
	int static	len;

	(void) ptr;
	(void) info;
	if (sig == SIGUSR1)
		len++;
	if (len == g_str_len)
	{
		ft_putstr_fd("Message Received\n", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = message;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		ft_putstr_fd("MUST HAVE 3 ARGUMENTS!\n", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	check_args(pid, argv[2]);
	g_str_len = ft_strlen(argv[2]);
	ft_str_to_binary(pid, argv[2]);
	return (0);
}
