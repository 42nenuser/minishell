/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 08:43:21 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:15:22 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nuber_of_words(char const *s, char c)
{
	int	result;

	result = 0;
	while (s[0])
	{
		if (s[0] != c)
		{
			result++;
			s++;
			while (s[0] && s[0] != c)
				s++;
		}
		else
			s++;
	}
	return (result);
}

static int	get_word_length(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[0] != c && s[0])
	{
		count++;
		s++;
	}
	return (count);
}

static int	repeated_char_length(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] == c)
		count++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	*temp;
	char	**result;
	int		result_length;
	int		i;

	if (!s)
		return (NULL);
	temp = (char *)s;
	temp += repeated_char_length(temp, c);
	i = 0;
	result_length = get_nuber_of_words(temp, c);
	result = ft_calloc(result_length + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (i < result_length)
	{
		if (ft_strlen(temp) == 1)
			result[i] = ft_strdup(temp);
		else
			result[i] = ft_substr(temp, 0, get_word_length(temp, c));
		temp += ft_strlen(result[i]);
		temp += repeated_char_length(temp, c);
		i++;
	}
	return (result);
}
