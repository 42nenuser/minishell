/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:34:29 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:40:26 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//checkes len number of characters in the big string
//looking for a match to the little string
//if found it returns a string starting from the world i was looking for
//else it returns null
//example  big = "hello there"; little = "lo"; len = 5
//the result will be "lo there"

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_length;
	size_t	count;

	count = 0;
	little_length = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *) big);
	if (!big && !len)
		return (NULL);
	if (ft_strlen(big) < len)
		len = ft_strlen(big);
	while (count < len && big[count])
	{
		if (big[count] == little[0])
		{
			if (!ft_strncmp(big + count, little, little_length))
			{
				if ((little_length + count) > len)
					return (NULL);
				return ((char *)(big + count));
			}
		}
		count++;
	}
	return (NULL);
}
