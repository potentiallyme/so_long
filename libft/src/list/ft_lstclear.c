/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:18:13 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/18 14:28:01 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(long))
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	if (*lst == NULL)
		free(*lst);
	else if (del)
	{
		while (temp != NULL)
		{
			*lst = temp->next;
			del(temp->content);
			free(temp);
			temp = *lst;
		}
	}
}
