/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:41:17 by okamili           #+#    #+#             */
/*   Updated: 2023/05/15 12:41:18 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

void	free2d(void **ptr)
{
	int	index;

	index = 0;
	while (ptr && ptr[index])
		free(ptr[index++]);
	free(ptr);
}
