/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:07:51 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 06:05:30 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comparechar(const char a, const char *set)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (!(a - set[count++]))
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		length;

	if (!s1 || !set)
		return (NULL);
	while (comparechar(s1[0], set))
		s1++;
	length = ft_strlen(s1);
	while (length && comparechar(s1[length - 1], set))
		length--;
	result = ft_calloc(length + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (!s1[0])
		return (result);
	ft_memcpy(result, s1, length);
	return (result);
}
