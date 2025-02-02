/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_all_words.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:41:43 by okamili           #+#    #+#             */
/*   Updated: 2023/06/16 18:26:10 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

static int	new_str_size(char *str, char *w0, char *w1)
{
	size_t	w0_len;
	size_t	w1_len;
	size_t	str_len;
	size_t	match_count;

	w0_len = ft_strlen(w0);
	w1_len = ft_strlen(w1);
	str_len = ft_strlen(str);
	match_count = 0;
	while (str && w0 && str[0])
	{
		if (!ft_strncmp(str, w0, w0_len))
			match_count++;
		str++;
	}
	return (str_len + ((w1_len - w0_len) * match_count));
}

static char	*replaced_str(char *str, char *w0, char *w1)
{
	char	*result;
	size_t	result_length;

	result_length = new_str_size(str, w0, w1);
	result = ft_calloc(result_length + 1, 1);
	while (str && str[0])
	{
		if (w0 && !ft_strncmp(str, w0, ft_strlen(w0)))
		{
			ft_strlcpy(result, w1, result_length + 1);
			result += ft_strlen(w1);
			str += ft_strlen(w0);
		}
		else
			*result++ = *str++;
	}
	result -= result_length;
	return (result);
}

char	*replace_all_words(char *str, char *w0, char *w1, int usefree)
{
	char	*result;

	result = replaced_str(str, w0, w1);
	if (usefree == 1)
		free(str);
	return (result);
}
