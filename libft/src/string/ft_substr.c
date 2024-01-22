/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:33:10 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:46:04 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*ft_fill(char const *s, char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start < slen)
	{
		while (len-- && s[start])
			str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen || !len)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > slen - start)
		len = (slen - start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (ft_fill(s, str, start, len));
}
