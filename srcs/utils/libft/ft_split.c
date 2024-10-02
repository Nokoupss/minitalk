/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:43:16 by nbelkace          #+#    #+#             */
/*   Updated: 2023/11/16 13:29:08 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	size_t	i;
	int		mots;

	i = 0;
	mots = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			mots++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (mots);
}

int	size_word(const char *str, char c, int index)
{
	int	len;

	len = 0;
	while (str[index] != '\0' && str[index] != c)
	{
			index++;
			len++;
	}
	return (len);
}

char	**split_free(char **tab, int index)
{
	while (index >= 0)
	{
		free(tab[index]);
		index--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	tab = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		tab[j] = ft_substr(s, i, size_word(s, c, i));
		if (tab[j] == NULL)
			return (split_free(tab, j));
		i = i + size_word(s, c, i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
