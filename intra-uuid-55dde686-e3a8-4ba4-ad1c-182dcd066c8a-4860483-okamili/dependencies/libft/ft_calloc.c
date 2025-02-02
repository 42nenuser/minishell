/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:25:09 by okamili           #+#    #+#             */
/*   Updated: 2022/10/07 00:12:48 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//same as malloc the only difference is that the space allocated
//is not filled with garbage data, instead its cleaned
//by zeroing all the data

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*holder;

	holder = malloc(count * size);
	if (holder)
	{
		ft_bzero(holder, count * size);
		return (holder);
	}
	return (NULL);
}
