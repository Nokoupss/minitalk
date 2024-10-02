/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:38:32 by nbelkace          #+#    #+#             */
/*   Updated: 2024/01/31 13:49:30 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*readfile(int fd, char *stash)
{
	int		reading;
	char	*line_buffer;

	reading = 1;
	while (is_charset_gnl(stash) == 0 && reading > 0)
	{
		line_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (line_buffer == NULL)
			return (NULL);
		reading = read(fd, line_buffer, BUFFER_SIZE);
		if (reading < 0)
		{
			free(line_buffer);
			return (NULL);
		}
		line_buffer[reading] = '\0';
		stash = ft_strjoin_gnl(stash, line_buffer);
		free(line_buffer);
	}
	return (stash);
}

char	*copy_stash(char *stash)
{
	int		i;
	int		j;
	char	*copy;

	if (stash == NULL)
		return (NULL);
	if (stash[0] == '\0')
		return (NULL);
	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	copy = (char *)malloc((i + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (j < i)
	{
		copy[j] = stash[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

char	*vide_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	if (stash[0] == '\0')
		return (free(stash), NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	new_stash = (char *)malloc(((ft_strlen(stash) - i) + 1) * sizeof(char));
	if (new_stash == NULL)
		return (NULL);
	while (stash[i] != '\0')
	{
		new_stash[j++] = stash[i];
		i++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*copy;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = readfile(fd, stash);
	copy = copy_stash(stash);
	stash = vide_stash(stash);
	if (stash == NULL)
		return (NULL);
	return (copy);
}
