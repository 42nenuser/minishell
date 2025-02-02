/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:46:49 by okamili           #+#    #+#             */
/*   Updated: 2022/10/06 22:32:21 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//writes len number of bytes of value c in the string txt
//example char str[] = "hello";
//memset(str, 'x', 2);
//will modify the value of str and return the new value
//memset return will be "xxllo";
//and value of str has change to "xxllo"

#include "libft.h"

void	*ft_memset(void *txt, int c, size_t len)
{
	unsigned char	*holder;
	size_t			count;

	count = 0;
	holder = (unsigned char *)txt;
	while (count < len)
	{
		holder[count++] = (unsigned char) c;
	}
	return (txt);
}
