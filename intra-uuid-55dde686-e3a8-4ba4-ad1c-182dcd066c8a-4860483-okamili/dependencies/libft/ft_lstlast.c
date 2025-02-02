/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:55:55 by okamili           #+#    #+#             */
/*   Updated: 2022/10/12 05:09:38 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	length;

	if (!lst)
		return (NULL);
	length = ft_lstsize(lst);
	while (length-- > 1)
	{
		lst = lst->next;
	}
	return (lst);
}
