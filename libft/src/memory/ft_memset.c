/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:39:36 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:46:56 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memset(void *s, int c, size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (size--)
	{
		*str = (unsigned char)c;
		str++;
	}
	return (s);
}
