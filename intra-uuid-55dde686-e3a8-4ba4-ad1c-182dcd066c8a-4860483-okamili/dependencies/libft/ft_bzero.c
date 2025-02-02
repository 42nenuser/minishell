/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:07:55 by okamili           #+#    #+#             */
/*   Updated: 2022/10/06 22:33:09 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//same as memset but the only different is that it rewrite all the values to 0

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, 0, n);
}
