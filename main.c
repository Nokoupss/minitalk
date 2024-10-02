/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjy <nadjy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 04:00:07 by nadjy             #+#    #+#             */
/*   Updated: 2024/09/27 07:37:40 by nadjy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum) {
	printf("Caught signal %d Exiting cleanly...\n", signum);
	exit(0);
}

int main() 
{
	signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    printf("Press Ctrl+C to trigger SIGINT signal...\n");
	printf("Kill PID to trigger SIGTERM signal...\n");
    
    while (1) {
        printf("Program is running...\n");
        sleep(3);
    }
    return 0;
}