/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjy <nadjy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 05:19:38 by nadjy             #+#    #+#             */
/*   Updated: 2024/10/03 04:07:54 by nadjy            ###   ########.fr       */
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

void	signal_handler(int signum)
{
	static char	*message;
	static int	ascii = 0;
	static int	bit = 0;

	if (message == NULL)
		message = ft_strdup("");
	if (signum == SIGUSR1)
		ascii = ascii + 0;
	else if (signum == SIGUSR2)
		ascii = ascii + (1 * ft_recursive_power(2, 7 - bit));
	bit++;
	if (bit == 8)
	{
		message = letter_to_string(message, ascii);
		if (ascii == '\0')
		{
			ft_printf("%s\n", message);
			message = NULL;
		}
		ascii = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;

	sigemptyset(&signal.sa_mask);
	ft_printf("Server's Open...\n");
	ft_printf("Server's PID: %d\n", getpid());
	signal.sa_handler = signal_handler;
	signal.sa_flags = 0;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		usleep(100);
}
