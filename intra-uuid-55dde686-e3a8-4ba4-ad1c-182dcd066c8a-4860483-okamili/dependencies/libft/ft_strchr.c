/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:13:22 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:16:20 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//search for c in the string s and returns the rest of string after that char c
//example
//s = "future" and c = 'u';
//the return will be "uture"

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	count;

	count = 0;
	while (count <= ft_strlen(s))
	{
		if (s[count++] == (char)c)
		{
			return ((char *)s + --count);
		}
	}
	return (NULL);
}
