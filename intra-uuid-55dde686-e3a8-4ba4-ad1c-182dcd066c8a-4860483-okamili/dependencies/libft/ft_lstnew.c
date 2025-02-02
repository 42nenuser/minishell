/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:17:15 by okamili           #+#    #+#             */
/*   Updated: 2022/10/12 01:11:04 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = ft_calloc(1, sizeof(t_list));
	if (result)
	{
		(*result).content = content;
		(*result).next = NULL;
		return (result);
	}
	return (NULL);
}
