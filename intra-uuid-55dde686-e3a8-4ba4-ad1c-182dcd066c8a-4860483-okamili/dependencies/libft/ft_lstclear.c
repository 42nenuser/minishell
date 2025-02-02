/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 07:37:49 by okamili           #+#    #+#             */
/*   Updated: 2022/10/13 06:53:28 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		length;
	t_list	*temp;

	if (!lst || !del)
		return ;
	length = ft_lstsize(*lst);
	while (length--)
	{
		del((*lst)->content);
		temp = (*lst)->next;
		(*lst)->next = NULL;
		free(*lst);
		*lst = temp;
	}
}
