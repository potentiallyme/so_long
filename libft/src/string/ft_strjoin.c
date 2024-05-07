/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:45:05 by lmoran            #+#    #+#             */
/*   Updated: 2024/02/05 15:51:00 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	if (!s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	i = 0;
	while (i < ft_strlen(s2))
	{
		str[(ft_strlen(s1) + i)] = s2[i];
		i++;
	}
	str[(ft_strlen(s1) + i)] = '\0';
	if (s1)
		free (s1);
	return (str);
}
