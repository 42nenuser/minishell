/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:01:51 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:25:19 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//it concatenate src to dst without overflowing the size

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	dst_length;
	size_t	count;

	if ((!dst && !src) && !dstsize)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	count = 0;
	if (dstsize <= dst_length)
		return (src_length + dstsize);
	while (src[count] && count < dstsize - dst_length -1)
	{
		dst[dst_length + count] = src[count];
		count++;
	}
	dst[dst_length + count] = '\0';
	return (src_length + dst_length);
}
