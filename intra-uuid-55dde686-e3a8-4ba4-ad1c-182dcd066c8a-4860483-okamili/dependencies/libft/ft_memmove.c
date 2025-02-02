/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:24:44 by okamili           #+#    #+#             */
/*   Updated: 2022/10/07 00:06:39 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//same as memcpy but it can handle the overlap

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_holder;
	unsigned char	*dst_holder;

	src_holder = (unsigned char *) src;
	dst_holder = (unsigned char *) dst;
	if (dst_holder > src_holder)
	{
		while (len-- > 0)
		{
			dst_holder[len] = src_holder[len];
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst_holder);
}
