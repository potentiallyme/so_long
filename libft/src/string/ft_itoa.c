/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:14:07 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:45:07 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_ilen(int n)
{
	if (n == 0)
		return (0);
	return (ft_ilen(n / 10) + 1);
}

static int	ft_lenc(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = (ft_ilen(n) + 1);
	else if (n == 0)
		len = 1;
	else
		len = ft_ilen(n);
	return (len);
}

static char	*ft_intmin(char *str, int len)
{
	int	nb;
	int	i;

	nb = 147483648;
	i = 1;
	str[0] = '-';
	str[1] = '2';
	while (nb != 0)
	{
		str[(len - i)] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	return (str);
}	

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;

	len = ft_lenc(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == -2147483648)
		return (ft_intmin(str, len));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	i = 1;
	while (n != 0)
	{
		str[(len - i++)] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
