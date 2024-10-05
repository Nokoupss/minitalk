/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 05:19:38 by nadjy             #+#    #+#             */
/*   Updated: 2024/10/05 21:25:06 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		res = nb * ft_recursive_power(nb, power - 1);
		return (res);
	}
}

char	*letter_to_string(char *s1, char letter)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (exit(0), NULL);
	tab = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		tab[j] = s1[i];
		j++;
		i++;
	}
	tab[j] = letter;
	j = j + 1;
	tab[j] = '\0';
	free((s1));
	return (tab);
}

void    signal_handler(int signum, siginfo_t *info, void *context)
{
    static char    *message;
    static int    ascii = 0;
    static int    bit = 0;
    pid_t        client_pid;

    (void)context;
    client_pid = info->si_pid;
    if (message == NULL)
        message = 0;
    if (signum == SIGUSR1)
        ascii = ascii + 0;
    else if (signum == SIGUSR2)
        ascii = ascii + (1 * ft_recursive_power(2, 7 - bit));
    bit++;
    if (bit == 8)
    {
        message = letter_to_string(message, ascii);
        if (ascii == '\0')
            ft_printf("%s\n", message);
        if (ascii == '\0')
            message = NULL;
        ascii = 0;
        bit = 0;
    }
    kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	signal;

	sigemptyset(&signal.sa_mask);
	signal.sa_sigaction = signal_handler;
	signal.sa_flags = SA_SIGINFO;
	ft_printf("Server's Open...\n");
	ft_printf("Server's PID: %d\n", getpid());
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		usleep(100);
}
