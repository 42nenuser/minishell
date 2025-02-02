/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:00:23 by okamili           #+#    #+#             */
/*   Updated: 2022/10/07 00:10:16 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//same as strncmp but it doesnt stop at the null terminator

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	unsigned char	*txt1;
	unsigned char	*txt2;

	txt1 = (unsigned char *)s1;
	txt2 = (unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (txt1[counter] == txt2[counter])
		{
			counter++;
		}
		else
		{
			return (txt1[counter] - txt2[counter]);
		}
	}
	return (0);
}
