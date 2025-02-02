/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 01:59:39 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:20:37 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//it allocate a new memory then it concat s1 and s2 to it
//and finaly it returns a pointer to the location of that
//new space that contains the concatenation of the both
//strings

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*holder;
	size_t	count1;
	size_t	count2;

	if (!s1 || !s2)
		return (NULL);
	count1 = 0;
	count2 = 0;
	holder = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (holder)
	{
		while (count1 < ft_strlen(s1))
		{
			holder[count1] = s1[count1];
			count1++;
		}
		while (count2 < ft_strlen(s2))
		{
			holder[count1 + count2] = s2[count2];
			count2++;
		}
		return (holder);
	}
	return (NULL);
}
