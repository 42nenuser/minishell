/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:04:59 by okamili           #+#    #+#             */
/*   Updated: 2022/10/06 22:07:12 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Checks if the input is either a digit or a character in the alphabet

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
