/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:53:28 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:27:55 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		length;
	int		count;

	if (!s || !f)
		return (NULL);
	count = 0;
	length = ft_strlen(s);
	result = ft_calloc(length + 1, sizeof(char));
	if (result)
	{
		ft_memcpy(result, s, length);
		while (count < length)
		{
			result[count] = f(count, result[count]);
			count++;
		}
		return (result);
	}
	return (NULL);
}
