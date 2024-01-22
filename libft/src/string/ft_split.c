/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:36:35 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/18 11:38:45 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	count_words(const char *s, char c)
{
	int		i;
	int		trigger;

	i = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (i);
}

static void	write_word(char *dest, char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
}

static int	write_split(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i])
			i++;
		else
		{
			j = 0;
			while (s[(i + j)] != c && s[(i + j)])
				j++;
			tab[word] = malloc(sizeof(char) * (j + 1));
			if (!tab[word])
				return (0);
			write_word(tab[word], s + i, c);
			i += j;
			word++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = NULL;
	write_split(res, s, c);
	return (res);
}
