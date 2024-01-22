/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:04:19 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:46:02 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	size_t	cst;
	size_t	cen;
	char	*ret;

	cst = 0;
	if (!s)
		return (NULL);
	while (s[cst] && ft_strchr(set, s[cst]))
		cst++;
	cen = ft_strlen(s);
	while (cen > cst && ft_strchr(set, s[cen - 1]))
		cen--;
	ret = malloc(sizeof(*s) * (cen - cst + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (cst < cen)
		ret[i++] = s[cst++];
	ret[i] = '\0';
	return (ret);
}
