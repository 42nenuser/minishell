/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 05:54:33 by okamili           #+#    #+#             */
/*   Updated: 2022/10/12 07:29:49 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	if (lst && new)
	{
		if (!*lst)
		{
			*lst = new;
		}
		else
		{
			lastnode = ft_lstlast(*lst);
			(*lastnode).next = new;
		}
	}
}
