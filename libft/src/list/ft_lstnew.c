/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:43:42 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/16 18:46:34 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstnew(long content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->index = 0;
	newnode->group = 0;
	newnode->cost_a = -1;
	newnode->cost_b = -1;
	newnode->next = NULL;
	return (newnode);
}
