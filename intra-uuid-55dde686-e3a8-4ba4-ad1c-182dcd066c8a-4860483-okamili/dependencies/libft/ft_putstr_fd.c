/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 02:49:06 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:13:43 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//write a string to a file

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, &s[0], ft_strlen(s));
}
