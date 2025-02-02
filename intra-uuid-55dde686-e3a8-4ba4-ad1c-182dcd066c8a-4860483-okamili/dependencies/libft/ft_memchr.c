/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:21:34 by okamili           #+#    #+#             */
/*   Updated: 2022/10/13 14:08:17 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//same as strchr but it doesnt stop at the null terminator

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;
	char	*holder;

	count = 0;
	holder = (char *)s;
	while (count < n)
	{
		if (holder[count++] == (char)c)
		{
			return ((char *)s + --count);
		}
	}
	return (NULL);
}
