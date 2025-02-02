/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:48:46 by okamili           #+#    #+#             */
/*   Updated: 2023/05/08 00:48:56 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*result;

	result = ft_calloc(1, size);
	ft_memcpy(result, ptr, size);
	free(ptr);
	return (result);
}
