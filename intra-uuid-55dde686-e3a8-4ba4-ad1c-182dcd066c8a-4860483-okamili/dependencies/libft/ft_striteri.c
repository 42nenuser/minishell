/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:35:45 by okamili           #+#    #+#             */
/*   Updated: 2022/10/10 22:50:20 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;
	unsigned int	length;

	if (s && f)
	{
		count = 0;
		length = ft_strlen(s);
		while (count < length)
		{
			f(count, &s[count]);
			count++;
		}
	}
}
