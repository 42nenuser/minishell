/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 02:03:11 by okamili           #+#    #+#             */
/*   Updated: 2023/05/15 02:04:02 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//same as memcpy but it stopes at the null terminator

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	count;

	src_length = ft_strlen(src);
	if (dstsize && !src_length)
		return (0);
	if (!dstsize)
		return (src_length);
	count = 0;
	while (count < (dstsize - 1) && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (src_length);
}
