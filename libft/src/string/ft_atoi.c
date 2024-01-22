/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:19:30 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/18 11:28:05 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

long	ft_atoi(const char *s)
{
	int	sign;
	long	n;
	int	i;

	sign = 1;
	n = 0;
	i = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		sign *= (-1);
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= 48 && s[i] <= 57)
	{
		n = n * 10 + s[i] - 48;
		i++;
	}
	return (n * sign);
}
