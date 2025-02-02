/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:02:36 by okamili           #+#    #+#             */
/*   Updated: 2022/10/13 07:07:38 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	length;

	if (!lst || !f)
		return ;
	length = ft_lstsize(lst);
	while (length--)
	{
		f(lst->content);
		lst = lst->next;
	}
}
