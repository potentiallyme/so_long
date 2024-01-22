/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:03:13 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/22 19:19:10 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_isvals(char *s, char *c)
{
	int i;
	int j;
	int x;

	i = 0;
	x = 0;
	while (s[i])
	{
		j = 0;
		while (c[j])
		{
			if (!(c[j] == s[i]))
				x = 1;
			else if (c[j] == s[i])
			{
				x = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	if (x)
		return (0);
	return (1);
}