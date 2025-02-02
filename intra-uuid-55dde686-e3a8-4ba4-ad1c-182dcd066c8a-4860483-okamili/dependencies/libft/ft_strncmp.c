/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:37:19 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:34:42 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//it compares the first n chars in the strings
//by subtracting str2 from str1

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;

	count = 0;
	while (count < n)
	{
		if (s1[count] == s2[count]
			&& s1[count] && s2[count])
			count++;
		else
		{
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		}
	}
	return (0);
}
