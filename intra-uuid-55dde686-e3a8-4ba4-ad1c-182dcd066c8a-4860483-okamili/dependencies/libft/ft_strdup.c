/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:12:05 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:17:09 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//it allocates memmory and copies the value s1 to the new space
//then it returns a pointer to that new space

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	int		count;
	char	*result;

	length = ft_strlen(s1);
	result = ft_calloc((length + 1), sizeof(char));
	count = 0;
	if (result)
	{
		while (count < (length))
		{
			result[count] = s1[count];
			count++;
		}
		return (result);
	}
	return (NULL);
}
