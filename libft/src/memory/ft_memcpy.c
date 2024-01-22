/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:36:26 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:46:54 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char	*tsrc;
	char	*tdst;

	if (!dst && !src)
		return (NULL);
	tsrc = (char *)src;
	tdst = (char *)dst;
	while (size-- > 0)
		*tdst++ = *tsrc++;
	return (dst);
}
