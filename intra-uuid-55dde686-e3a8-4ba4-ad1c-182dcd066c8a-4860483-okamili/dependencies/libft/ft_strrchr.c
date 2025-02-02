/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:23:33 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:43:40 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//search for c in the string s but in reverse
//and returns the rest of string after that char c
//example
//s = "future" and c = 'u';
//the return will be "ure"

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = ft_strlen(s);
	while (count >= 0)
	{
		if (s[count--] == (char)c)
		{
			return ((char *)s + ++count);
		}
	}
	return (NULL);
}
