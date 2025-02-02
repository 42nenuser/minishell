/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:59:48 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 07:31:53 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_length(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	int_to_char(char *dst, int n)
{
	int	count;

	count = int_length(n) - 1;
	if (n < 0)
	{
		n *= -1;
		dst[0] = '-';
	}
	while (n)
	{
		dst[count--] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;

	if (!n)
		return (ft_strdup("0"));
	result = ft_calloc(int_length(n) + 1, sizeof(char));
	if (result)
	{
		if (n == -2147483648)
		{
			ft_memcpy(result, "-2147483648", 11);
			return (result);
		}
		int_to_char(result, n);
		return (result);
	}
	return (NULL);
}
