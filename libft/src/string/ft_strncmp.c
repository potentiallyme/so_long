/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:45:28 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:45:52 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	if (size < 1)
		return (0);
	while ((t1[i] == t2[i]) && (i < (size - 1)) && (t1[i]))
		i++;
	return (t1[i] - t2[i]);
}
