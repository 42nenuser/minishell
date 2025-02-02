/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:30:36 by okamili           #+#    #+#             */
/*   Updated: 2022/10/06 21:54:09 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Checks to see if the input belongs to the alphabet

int	ft_isalpha(int ASCII_VALUE)
{
	return ((ASCII_VALUE >= 'A' && ASCII_VALUE <= 'Z')
		|| (ASCII_VALUE >= 'a' && ASCII_VALUE <= 'z'));
}
