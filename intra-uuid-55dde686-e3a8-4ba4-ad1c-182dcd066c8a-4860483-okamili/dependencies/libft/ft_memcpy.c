/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:01:37 by okamili           #+#    #+#             */
/*   Updated: 2023/04/23 07:46:34 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copies dst to the src
//example dst = "hello" src = "test"
//result will be dst = "testo";

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_holder;
	unsigned char	*dst_holder;
	size_t			counter;

	src_holder = (unsigned char *) src;
	dst_holder = (unsigned char *) dst;
	if (!dst_holder || (!src_holder && !dst_holder))
		return (NULL);
	if (!src_holder)
		return (dst_holder);
	counter = 0;
	while (counter < n)
	{
		*(unsigned char *)(dst + counter) = src_holder[counter];
		counter++;
	}
	return (dst_holder);
}
