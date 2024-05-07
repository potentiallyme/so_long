/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:36:35 by lmoran            #+#    #+#             */
/*   Updated: 2024/02/05 15:55:09 by lmoran           ###   ########.fr       */
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

char	**ft_split(char *s, char c, int free_or_not)
{
	char	**res;
	int		words;

	if (!s)
		return (0);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (0);
	res[words] = 0;
	write_split(res, s, c);
	if (free_or_not == 1)
		free(s);
	return (res);
}
