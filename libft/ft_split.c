/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:42:20 by gdaignea          #+#    #+#             */
/*   Updated: 2024/03/20 14:07:00 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count_words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count_words);
}

static char	**fill_tab(char const *s, char c, char **tab, int nb_words)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && k < nb_words)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		tab[k] = ft_substr(s, j, i - j);
		k++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	char	**tab;

	nb_words = count_words(s, c);
	tab = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = fill_tab(s, c, tab, nb_words);
	tab[nb_words] = NULL;
	return (tab);
}
