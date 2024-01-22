/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:07:09 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/22 18:16:02 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strlen_double(char **s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i++])
		len += ft_strlen(s[i]);
	return (len);
}