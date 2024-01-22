/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:10:39 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:45:55 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(const char *b, const char *s, size_t size)
{
	size_t	i;
	size_t	j;

	if (!*s)
		return ((char *)b);
	i = 0;
	while ((i < size) && b[i])
	{
		j = 0;
		if (b[i] == s[j])
		{
			while ((b[i + j] == s[j]) && (s[j] != '\0') && (i + j < size))
				j++;
		}
		if (!s[j])
		{
			return ((char *)(b + i));
		}
		i++;
	}
	return (NULL);
}
