/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:36:44 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:46:49 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	char	*tsrc;
	char	*tdst;
	size_t	i;

	tsrc = (char *)src;
	tdst = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (dst);
	if (tdst > tsrc)
		while (size-- > 0)
			tdst[size] = tsrc[size];
	else
	{
		while (i < size)
		{
			tdst[i] = tsrc[i];
			i++;
		}
	}
	return (dst);
}
