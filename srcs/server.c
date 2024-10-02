/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjy <nadjy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 05:19:38 by nadjy             #+#    #+#             */
/*   Updated: 2024/09/27 12:20:53 by nadjy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void handle_sigusr1(int signum) 
{
	ft_printf("Caught SIGUSR1 %d\n", signum);
}

void handle_sigusr2(int signum) 
{
	ft_printf("Caught SIGUSR2 %d\n", signum);
}

int	main(void)
{
	struct sigaction action;
	
	action.sa_handler = handle_sigusr1;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("Server Launched\n");
	ft_printf("Server's PID : %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
