/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:36:33 by okamili           #+#    #+#             */
/*   Updated: 2023/05/15 01:56:02 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//return the length of the string

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	total;

	total = 0;
	while (s && s[total] != '\0')
	{
		total++;
	}
	return (total);
}
