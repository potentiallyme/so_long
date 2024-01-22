/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:50:40 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:46:43 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if ((nmemb * size < nmemb || size > (nmemb * size)) && size && nmemb)
		return (NULL);
	s = malloc(size * nmemb);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
