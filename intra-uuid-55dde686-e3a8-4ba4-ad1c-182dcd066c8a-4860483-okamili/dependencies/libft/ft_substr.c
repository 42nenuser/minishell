/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:00:54 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:49:04 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*result;

	if (!s || start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	result = ft_calloc((len + 1), sizeof(char));
	if (!result)
		return (NULL);
	count = 0;
	while (count < len && s[start + count])
	{
		result[count] = s[start + count];
		count++;
	}
	return (result);
}
