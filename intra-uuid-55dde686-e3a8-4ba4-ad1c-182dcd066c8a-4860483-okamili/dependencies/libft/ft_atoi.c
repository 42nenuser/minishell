/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:46:30 by okamili           #+#    #+#             */
/*   Updated: 2022/10/07 02:24:15 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//turns numbers from string to int
// "213" => 213

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	count;

	result = 0;
	sign = 1;
	count = 0;
	while (str[count] == ' ' || str[count] == '\t' || str[count] == '\v'
		|| str[count] == '\f' || str[count] == '\r' || str[count] == '\n')
	{
		count++;
	}
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (ft_isdigit(str[count]))
	{
		result = (result * 10) + (str[count++] - '0');
	}
	return (result * sign);
}
